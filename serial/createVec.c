void createVec(int n, long* vec){
  long mrand48();
  int i;
  for(i = 0; i < n; i++){
    vec[i] = mrand48();
  }
}
