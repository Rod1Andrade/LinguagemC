
#include <stdio.h>
#include <stdlib.h>

float S(int n){
  if(n > 0)
    return (1+n*n)/(float)n + S(n-1);
  else
    return 0;
}

int main(void){
  printf("%.2f\n", S(5));
}
