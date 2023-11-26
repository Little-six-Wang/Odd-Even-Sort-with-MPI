#include<stdlib.h>

void createVec(int n, long*a){
  int i;
  long mrand48();
  for(i = 0; i < n; i++){
    a[i] = mrand48();
  }
}
