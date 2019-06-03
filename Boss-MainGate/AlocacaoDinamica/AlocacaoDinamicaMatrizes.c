#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  
  /**
   * Alocação de arrays multidimensionais:
   * Para alocar um array com mais de 1 dimensão, precisamos utilizar o conceito de 
   * ponteiro de ponteir.
   *
   * */

  int tam = 2;

  //Ponteiro de 1 nível:
  int *p1 = (int *) calloc(tam, sizeof(int));

  //Ponteiro para Ponteiro (2 Níveis): 
  int **Matriz; //Um ponteiro de 2 níveis é uma matriz.

  //Ponteiro para Ponteiro para ponteiro (3 Níveis):
  int ***Dimensao;

  /**
   * int* -> Permite criar um array de int
   * int ** -> permite criar um array para array de int (ou array de int *)
   *
   * */
  //Dois níveis --> Uma matriz
  int **p2;

  //Aloca espaço na memória com um casting para o tipo (int **)  (matriz) e um size of para um tamanho de ponteiro para inteiro (int *)
  p2 = (int **) calloc(tam, sizeof(int *));

  //Criou um array de ponteiro, que aponta para um array de ponteiro, agora
  //deve se para cada posição desse array, alocar um espaço de memória para guardar
  //um inteiro.
  for(int i = 0; i < tam; i++)
  {
    p2[i] = (int *) calloc(tam, sizeof(int));
  }

  //Libera o espaço alocado das colunas:
  for(int i = 0; i < tam; i++)
    free(p2[i]);

  //Libera espaço alocado das linhas:
  free(p2);

  return 0;
}
