EXE = subtest/exec
target_1 = Odd_even_sort
target_2 = test
THREAD = 4
export target_1 target_2


clean:
	rm -f subtest/parallel/*.o subtest/serial/*.o $(EXE)/*

run:
	make -C subtest/serial
	make -C subtest/parallel
	./$(EXE)/$(target_2)
	mpiexec -n $(THREAD) ./$(EXE)/$(target_1)
	make clean
