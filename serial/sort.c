void sort(int n, long* a){
  int phase, i;
  long temp;
  for(phase = 0; phase < n; phase++){
    if(phase % 2 == 0){
      for(i = 1; i < n; i += 2){
        if(a[i] <= a[i - 1]){
          temp = a[i];
          a[i] = a[i - 1];
          a[i - 1] = temp;
        }
      }
    }else{
      for(i = 1; i < n - 1; i += 2){
        if(a[i + 1] <= a[i]){
          temp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = temp;
        }
      }
    }
  }
}
