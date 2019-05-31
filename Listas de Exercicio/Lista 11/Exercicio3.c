#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, NULL); 
  
  int Produto = 1, Count = 1;

  do
  {
    Produto *= Count++;
  }while(Count <= 6);

  printf("Produto dos números entre 1 e 6 é: %d\n", Produto);
  
  return 0;
}
