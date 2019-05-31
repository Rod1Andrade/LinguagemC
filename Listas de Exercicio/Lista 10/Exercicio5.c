#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  //Série do valor H
  //H = 1/1 + 3/2 + 5/3 + 7/4 + … + 99/50
  float Numerador = 1, Denominador = 1, H;   

  while(Numerador < 100)
  {
    H += Numerador / Denominador;
    Numerador += 2;
    Denominador++;
  }

  printf("H = %.2f\n", H);

  return 0;
}
