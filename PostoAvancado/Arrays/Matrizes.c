#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
  
  //Arrays Multidimensionais: 
  char Matriz[3][3]; 

  //Três dimensões
  char Cubo[3][3][3];

  //Quatro dimensões
  char Quad[3][3][3][3];

  //Adcionando valores em um array de quatro dimensões:
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      for(int k = 0; k < 3; k++)
      {
        for(int z = 0; z < 3; z++)
        {
          Quad[i][j][k][z] = 0;
          printf("%d", Quad[i][j][k][z]); 
        }
        printf("\n");
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
