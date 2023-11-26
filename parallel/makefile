objects = get_input.o Print_num.o Read_num.o createVec.o sort.o merge_low.o merge_high.o get_partner.o \
Odd_even_sort.o

CC = mpicc
INCLDUE = -I ./../../include


%.o:%.c
	$(CC) $(INCLDUE) -c $< -o $@

$(target_1):$(objects)
	$(CC) -g -Wall -o ../exec/$@ $(objects)
