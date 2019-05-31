#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, NULL);

  int Soma = 3, Count = 4; 

  do
  {
    Soma += Count++;  
  }while(Count <= 10);
  
  printf("Soma dos números entre 3 e 10 é: %d\n", Soma);

  return 0;
} 
