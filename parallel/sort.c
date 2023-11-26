#include<stdio.h>
#include<mpi.h>

int get_partner(int, int, int);
void merge_low(int, int, long**, long*);
void merge_high(int, int, long**, long*);
void sort(int comm_sz, int my_rank, int local_n, long** key, long* recv, MPI_Comm comm){
  int q;
  int partner;
  for(q = 0; q < comm_sz; q++){
    partner = get_partner(q, my_rank, comm_sz);
    MPI_Sendrecv((*key), local_n, MPI_LONG, partner, 0, recv, local_n, MPI_LONG, partner, 0, comm, MPI_STATUS_IGNORE);

    if(partner != MPI_PROC_NULL){
      if(my_rank < partner){
        merge_low(my_rank, local_n, key, recv);
      }else{
        merge_high(my_rank, local_n, key, recv);
      }
    }
  }
}
