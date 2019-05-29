#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  //Inicializando ArrAY
  int vet[] = {15, 12, 13, 14, 16};
  int matriz[3][3] = {
    {7, 8, 9},
    {4, 5, 6},
    {1, 2, 3}
  };

  for(int linha = 0; linha < 3; linha++)
  {
    for(int coluna = 0; coluna < 3; coluna++)
    {
      if(coluna == 1)
        printf("|%d|", matriz[linha][coluna]);
      else
        printf("%d", matriz[linha][coluna]);
    }
    printf("\n");
  }
  
  return 0;
}
