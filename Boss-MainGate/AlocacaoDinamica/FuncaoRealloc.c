#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  /**
   * Realloc() :-: Recebe por parâmetro
   * - Ponteiro para um bloco de memória já alocado:
   * - A quantidade de bytes que deseja alocar
   * e retorna: 
   *    - NULL :-: Caso de algum erro;
   *    - Ponteiro para a primeira posição do array.
   *
   * */

  printf("Memória estática inicial: \n");
  //Alocando memória utilizando o calloc:
  int *v = (int *) calloc(5, sizeof(int));

  for(int i = 0; i < 5; i++)
  {
    v[i] = i*2;
    printf("v[%d] = %d\n", i, v[i]);
  }

  printf("\nMemória do vetor realocada: \n");
  //Realocando a memória para 10
  v = (int *) realloc(v, 10);
  
  //Realloc copia os dados anteriores já alocado na memória
  for(int i = 5; i < 10; i++)
  {
    v[i] = i*2;
  }

  for(int i = 0; i < 10; i++)
    printf("v[%d] = %d\n", i, v[i]);
    

  //Liberando espaço na memória: 
  free(v);

  /**
   * Se previamente o bloco de memória alocada for NULL
   * a função realloc() irá alocar memória da mesma forma como
   * a função malloc.
   * */

  //Exemplo: 
  int *p = NULL;

  //Utilizando realloc como o malloc
  p = (int *) realloc(p, 2*sizeof(int));

  p[0] = 10;
  p[1] = 100;

  printf("\nAlocando memoria com o realloc:\n");
  for(int i = 0; i < 2; i++)
    printf("[%d] = %d\n", i, p[i]);

  /**
   * Você também pode realocar o vetor para 0
   * void * realloc(*<tipo>, unsigned int size);
   *
   * */

  //Equivale ao free();
  p = (int *) realloc(p, 0);

  //Liberando Espaço de memória
  free(p);


  /*
   * Cuidado para se tomar ao utilizar o REALLOC
   * se não houver memória suficiente para alocar a memória
   * requisitada, a função realloc retornara nulo para o ponteiro:
   *
   * Então utiliza-se uma verificação para garantir a integridade dos dados:
   *
   * **/
  
  int *pointer = (int *) calloc(5, sizeof(int));
  int *pointerVerifica = (int *) realloc(p, 10);

  //Deste modo se garante a integridade dos dados já contido na alocação de memória anterior
  if(pointerVerifica != NULL)
    pointer = pointerVerifica;

  free(pointer);

  return 0;
}
