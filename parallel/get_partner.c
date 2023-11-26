#include<mpi.h>

int get_partner(int phase, int my_rank, int comm_sz){
  int partner;
  if(phase % 2 == 0){
    if(my_rank % 2 == 0){
      partner = my_rank + 1;
    }else{
      partner = my_rank - 1;
    }
  }else{
    if(my_rank % 2 == 0){
      partner = my_rank - 1;
    }else{
      partner = my_rank + 1;
    }
  }
  if(partner == -1 || partner == comm_sz){
    partner = MPI_PROC_NULL;
  }
  return partner;
}
