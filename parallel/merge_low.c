#include<stdio.h>
#include<stdlib.h>

void merge_low(int my_rank, int local_n, long** key, long* recv){
  int k_i = 0, r_i = 0, t_i = 0;
  long* temp = NULL, *temp_pntr = NULL;
  temp = malloc(local_n * sizeof(long));
  
  while(t_i < local_n){
    if((*key)[k_i] <= recv[r_i]){
      temp[t_i++] = (*key)[k_i++];
    }else{
      temp[t_i++] = recv[r_i++];
    }
  }
  
  
  //just swap the pointer
  temp_pntr = temp;
  *key = temp;
  temp = temp_pntr;
}
