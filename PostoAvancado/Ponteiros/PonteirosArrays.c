#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  //Tamanhos dos tipos de ponteiros
  char *ponteiroChar;
  int *ponteiroInt;
  float *ponteiroFloat;
  double *ponteiroDouble;

  printf("Tamanho Ponteiros: \n");
  printf("char = %zu byte\n", sizeof(*ponteiroChar));
  printf("int = %zu bytes\n", sizeof(*ponteiroInt));
  printf("float = %zu bytes\n", sizeof(*ponteiroFloat));
  printf("double = %zu bytes\n\n", sizeof(*ponteiroDouble));

  //Apontadores e vetores: 
  char vetor[3];
  char *ponteiroVetor;

  //ponteiroVetor = &vetor[0];
  ponteiroVetor = vetor;

  /**
   * Essa sintaxe é completamente aceitavel pelo fato de: 
   * Em C o nome de um vetor já expressa sua posição inicial 
   * logo:
   *    -  ponteiroVetor = &vetor[0];
   *    -  ponteiroVetor = vetor;
   * O valor inicial de um vetor, também é o seu endereço, visto que
   * no príncipio básico, um vetor, é um bloco contigo de memória (em sequência).
   * */

  //Aritmética de Endereços:
  //Iniciando Valores
  printf("Método 1: \n");
  for(int i = 0; i < 3; i++)
    *(ponteiroVetor + i) = 97 + i;

  //Imprimindo endereços e valores:
  for(int i = 0; i < 3; i++)
    printf("%p = %c\n", ponteiroVetor+i, *(ponteiroVetor+i));

  printf("\nMétodo 2: \n");
  //Imprimindo endereços e valores:
  for(int i = 0; i < 3; i++)
    printf("%p = %c\n", ponteiroVetor+i, ponteiroVetor[i]);

  return 0;
} 
