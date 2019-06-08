#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /***
   * 1 
   * 2 3
   * 4 5 6
   * 7 8 9 10
   * 11 12 13 14 15 
   * 16 17 18 19 20 21
   *
   *
   * */

  int aux = 0, Limite; 
  printf("Digite um número inteiro: ");
  scanf("%d", &Limite);

  for(int i = 1; i <= Limite; i++)
  {
    for(int j = 1; j <= i; j++)
    {
      aux++;
      printf("%d ", aux);
    }
    printf("\n");
  }

  return 0;
}
