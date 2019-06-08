#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  ///FORMULA DE EULER: 1/1! + 1/2! + 1/3! + ...... 1/N!
  int EnesimoTermo;
  double Euler = 1.0;
  printf("Entre com um número para a sequência de euler: ");
  scanf("%d", &EnesimoTermo);
  for(int i = 1; i <= EnesimoTermo; i++)
  {
    ///Cálculo FATORIAL:
    long Fat = 1;
    for(int j = Fat; j <= i; j++)
      Fat *= j;

    ///SOMA de EULER:
    Euler += 1.0/(double)Fat;
  }

  printf("Euler: %.2f\n", Euler);
  return 0;
}

