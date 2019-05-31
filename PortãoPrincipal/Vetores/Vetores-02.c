#include <stdio.h>
#include <stdlib.h>

enum Materias {
   Matematica, 
   Fisica,
   Quimica
};

int main(int argv, char *argc[])
{
  
  //Vetores de Vetores: (Matrizes);
  float Notas[3][4];

  for(int linha = 0; linha < 3; linha++)
  {
    if(linha == Matematica)
      {
        printf("Entre com as notas de Matematica: \n");
      }//Fim do IF
    else if(linha == Fisica)
      {
        printf("Entre com as notas de Fisica: \n");
      }//Fim do else if
    else
      {
        printf("Entre com as notaas de Quimica: \n");
      }//Fim do else
    for(int coluna = 0; coluna < 4; coluna++)
    {
      printf("#%d: ", coluna+1);
      scanf("%f", &Notas[linha][coluna]);
    }//Fim do For interno
  }//Fim do For 
  
  //Imprimindo Matriz: 
  for(int i = 0; i < 3;i++)
  {
    for(int j = 0; j < 4; j++)
    {
      printf("Notas[%d][%d] = %.2f\n",i, j, Notas[i][j]);
    }
  }


  return 0;
}
