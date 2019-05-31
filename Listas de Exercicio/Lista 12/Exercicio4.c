#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");
  //Faça um programa para calcular e escrever o produto dos números entre 1 e 6.

  int Produto = 1;
  for(int i = 1; i <= 6; i++)
  {
    Produto *= i;
  }
  printf("Produto dos números entre 1 e 6: %d\n", Produto);
  
  return 0;
}
