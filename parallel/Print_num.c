#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void Print_num(long local_a[], int local_n, int n, int my_rank, MPI_Comm comm){
	long* b = NULL;
	int i;
	if(my_rank == 0){
		b = malloc(n * sizeof(long));
		MPI_Gather(local_a, local_n, MPI_LONG, b, local_n, MPI_LONG, 0, comm);
		printf("the num:\n");
		for(i = 0; i < n; i++){
			printf("%ld ", b[i]);
		}
		printf("\n");
		free(b);
	}else{
		MPI_Gather(local_a, local_n, MPI_LONG, b, local_n, MPI_LONG, 0, comm);
	}
}
