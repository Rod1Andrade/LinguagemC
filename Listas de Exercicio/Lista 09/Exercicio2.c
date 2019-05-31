#include <stdio.h>

int main(int argv, char *argc[])
{
  //Números pares utilizando o While.
  
  int Numero = 100;
  while(Numero <= 140)
  {
    printf("%d ", Numero);
    Numero += 2;
  }
  printf("\n");
  return 0;
}
