#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include"parameters.h"

void Read_num(long*, int, int, int, MPI_Comm);
void Print_num(long*, int, int, int, MPI_Comm);
void sort(int, int, int, long**, long*, MPI_Comm);

int main(){
	int comm_sz, my_rank;
	int q;
	int local_n;
	long* key_value = NULL, * recv_value = NULL;
	double local_start_time, local_final_time, local_elapsed;
	double elapsed;
	
	int cmpfunc(const void* a, const void* b){
	  return *(long*)a > *(long*)b ? 1 : -1;
	}
	
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	local_n = N / comm_sz;
	key_value = malloc(local_n * sizeof(long));
	recv_value = malloc(local_n * sizeof(long));
	
	Read_num(key_value, local_n, N, my_rank, MPI_COMM_WORLD);
	if(my_rank == 0){
	  printf("mpi = [\n");
	}
	Print_num(key_value, local_n, N, my_rank, MPI_COMM_WORLD);
	qsort(key_value, local_n, sizeof(long), cmpfunc);
	
	local_start_time = MPI_Wtime();
	sort(comm_sz, my_rank, local_n, &key_value, recv_value, MPI_COMM_WORLD);
	local_final_time = MPI_Wtime();
	local_elapsed = local_final_time - local_start_time;
	MPI_Reduce(&local_elapsed, &elapsed, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
	
	if(my_rank == 0){
	  printf(";\n");
	}
	Print_num(key_value, local_n, N, my_rank, MPI_COMM_WORLD);
	if(my_rank == 0){
	  free(key_value);
	  free(recv_value);
	  printf("]\n");
	  printf("parallel_sec = %lf", elapsed * 1000);
	}
	MPI_Finalize();
	return 0;
}
