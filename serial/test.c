#include<stdio.h>
#include<stdlib.h>
#include"parameters.h"

double dclock();
void createVec(int, long*);
void sort(int, long*);

int main(){
  double time_used;
  long* vec = NULL;
  
  vec = malloc(N * sizeof(long));
  
  createVec(N, vec);
  
  printf("serial = [\n");
  for(int i = 0; i < N; i++){
    printf("%ld ", vec[i]);
  }
  
  time_used = dclock();
  sort(N, vec);
  time_used = dclock() - time_used;
  
  printf(";\n");
  for(int i = 0; i < N; i++){
    printf("%ld ", vec[i]);
  }
  printf("]\n");
  
  printf("serial_sec = %lf\n", time_used * 1000);
  
  return 0;
}
