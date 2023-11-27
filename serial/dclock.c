#include<sys/time.h>
#include<time.h>

static double start_time_sec = 0.0;

double dclock(){
  double the_time;
  struct timeval tv;
  gettimeofday(&tv, NULL);
  //before
  if(start_time_sec == 0.0){
    start_time_sec = (double)tv.tv_sec;
  }
  //time consumed
  the_time = tv.tv_sec - start_time_sec;
  the_time = the_time + tv.tv_usec * 1.0e-6;
  return the_time;
}
