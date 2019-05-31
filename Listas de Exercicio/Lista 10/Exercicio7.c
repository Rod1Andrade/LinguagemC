#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  int n = 1;
  float S = 0;

  while(n <= 10)
  {
    //Par
    if(n%2 == 0)
    {
      S -= n / pow(n, 2);
    }
    //Impar
    else
    {
      S += n / pow(n, 2);
    }
    n++;
  }

  printf("Valor de S: %.2f\n", abs(S)); 

  return 0;
}
