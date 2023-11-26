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
	
	int cmpfunc(const void* a, const void* b){
	  return (*(int*)a - *(int*)b);
	}
	
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	local_n = N / comm_sz;
	key_value = malloc(local_n * sizeof(long));
	recv_value = malloc(local_n * sizeof(long));
	
	Read_num(key_value, local_n, N, my_rank, MPI_COMM_WORLD);
	if(my_rank == 0){
	  printf("before:\n");
	}
	Print_num(key_value, local_n, N, my_rank, MPI_COMM_WORLD);
	
	qsort(key_value, local_n, sizeof(long), cmpfunc);
	
	sort(comm_sz, my_rank, local_n, &key_value, recv_value, MPI_COMM_WORLD);
	
	if(my_rank == 0){
	  printf("after:\n");
	}
	Print_num(key_value, local_n, N, my_rank, MPI_COMM_WORLD);
	if(my_rank == 0){
	  free(key_value);
	  free(recv_value);
	  //free(temp);
	}
	MPI_Finalize();
	return 0;
}
