#include <stdio.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  //Escrever números inteiros de 1 a 15 utilizando o while.

  int Numero = 5;
  while(Numero <= 15)
  {
    printf("%d ", Numero);
    Numero++;
  }
  
  printf("\n");
  return 0;
}
