/**
 * A função malloc serve para alocar memória 
 * durante a execução do prgrama.
 * Ela faz o pedido de memória e retornar um 
 * ponteiro com o endereço para a primeira posição
 * do espaço de memória alocado. 
 *
 * Forma Geral: 
 * void * malloc(unsigned int num);
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  /**
   * Funcionamento:
   * A função malloc() recebe por parâmetro
   * a quantidade de bytes que deva ser alocada e retorna:
   *    - NULL: Caso de erro;
   *    - ponteiro para primeira posição da memória alocada, caso dê
   *    tuo certo.
   *
   * */

  //Exemplo
  //Cria um array de 50 inteiros ( 50 * 4 byte cada inteiro = 200 byte);
  //int *vetorInteiros = malloc(200);

  //Cria um array de 200 char ( 200 * 1 byte de cada char = 200 bytes );
  //char *vetorChar = malloc(200);
  //



  //Na alocação deve-se levar em conta o tamanho do tipo:
  //Exemplo: Criar um array de tamanho 50;
  //int *vetorInteiros = (int *)  malloc(sizeof(int) * 50);
  //char *vetorChar    = (char *) malloc(sizeof(char) * 50);

  //Exemplo na prática:
  int tam = 5;
  int *p;
  p = (int *) malloc(tam * sizeof(int));

  if(p == NULL)
  {
    printf("Erro: Sem memória!\n");
    exit(1); //Aborta o programa.
  }

  for(int i = 0; i < tam; i++)
  {
    printf("Digite p[%d]: ", i); 
    scanf("%d", &p[i]);
  }


  printf("\nIMPRIMINDO: \n");
  for(int i = 0; i < tam; i++)
  {
    printf("Digite p[%d]: %d\n", i, p[i]); 
  }
  
  //FREE --> Liberar o espaço alocado
  free(p);
  return 0;
}
