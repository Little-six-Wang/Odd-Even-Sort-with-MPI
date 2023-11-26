OBJ = test.o

%.o:%.c
	gcc -c $< -o $@

$(target_2):$(OBJ)
	gcc -o ../exec/$@ $(OBJ)
