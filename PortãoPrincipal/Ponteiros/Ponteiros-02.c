#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
  
  int x = 10;
  double d = 20.5;
  char c = 66;

  int *px = &x;
  double *pd = &d;
  char *pc = &c;

  double soma = *px + *pd;

  printf("Endereço px %d, Valor de px %d\n", px, *px);
  printf("Endereço dx %p, Valor de dx %.2f\n", pd, *pd);
  printf("Endereço cx %p, Valor de cx %d\n", pc, *pc);
  printf("Soma = %.2f\n", soma);

  return 0;
}

