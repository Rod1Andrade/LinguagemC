#include <stdio.h>
#include <stdlib.h>

//Princípio semelhante ao cálculo fatorial:
int soma(int n)
{
  if(n == 1)
    return 1;
  else
    return n + soma(n-1);
}

int main(void)
{

  //Função recursiva que calcule o somatório de 1 até n;
  int resultado = soma(9);

  printf("Soma de 1-9 = %d\n", resultado);
  return 0;
}
