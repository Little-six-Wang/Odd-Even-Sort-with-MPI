#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void createVec(int, long*);

void Read_num(long local_a[], int local_n, int n, int my_rank, MPI_Comm comm){
	long* a = NULL;
	int i;
	if(my_rank == 0){
		a = malloc(n * sizeof(long));
		createVec(n, a);
		MPI_Scatter(a, local_n, MPI_LONG, local_a, local_n, MPI_LONG, 0, comm);
		free(a);
	}else{
		MPI_Scatter(a, local_n, MPI_LONG, local_a, local_n, MPI_LONG, 0, comm);
	}
}
