#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  //Soma de todos os números entre 3 e 10
  int Soma = 0;
  for(int i = 3; i <= 10; i++)
  {
    Soma += i;
  }

  printf("Soma dos números entre 3 e 10: %d\n", Soma);
  
  return 0;
}
