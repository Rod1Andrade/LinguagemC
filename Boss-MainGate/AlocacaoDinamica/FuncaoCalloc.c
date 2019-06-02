/**
 *   A Função calloc tem um funcionamento semelhante a função malloc,
 *   porém, além de inicializar o vetor têm um protótipo de declaração diferente:
 *
 *   Protótipo:
 *   
 *   void * calloc(unsigned int num, unsigned int size);
 *   Retorna um ponteiro Genérico, necessita de casting.
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  //Alocação
  int tamanho = 5;
  int *vetorInteiro = (int *) calloc(tamanho, sizeof(int));
  
  if(vetorInteiro == NULL)
  {
    printf("Memória Insuficiente\n");
    exit(1);
  }

  //Mostrando o array que já é inicializado com 0 utizando o calloc.
  for(int i = 0; i < tamanho; i++)
  {
    printf("vetorInteiro[%d] = %d\n", i, vetorInteiro[i]);
  }

  //Libera o espaço utilizado
  free(vetorInteiro);

  return 0;
}
