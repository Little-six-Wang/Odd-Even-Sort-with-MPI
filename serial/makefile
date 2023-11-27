OBJ = test.o createVec.o dclock.o sort.o
INCLUDE = -I ./../../include

%.o:%.c
	gcc $(INCLUDE) -c $< -o $@

$(target_2):$(OBJ)
	gcc -o ../exec/$@ $(OBJ)
