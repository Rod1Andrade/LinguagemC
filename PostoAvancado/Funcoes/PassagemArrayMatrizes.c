#include <stdio.h>
#include <stdlib.h>

void imprime(int m[][3], int n)
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      printf("%d ", m[i][j]);

}

int main(void)
{
  
  /**
   * Arrays com mais de uma dimensão, precisam de informação do 
   * tamanho das outras dimensões;
   * 
   * */

  //Exemplo: 
  int matriz[3][3] = { 
    1,2,3,
    4,5,6,
    8,9,10
  };

  imprime(matriz, 3);
  return 0;
}
