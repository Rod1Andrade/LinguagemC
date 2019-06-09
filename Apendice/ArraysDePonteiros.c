#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  int vetor[5] = {1, 2, 3, 4, 5};

  ///Maneiras de associação de um array a um ponteiro:
  int *p1 = vetor;
  int *p2 = vetor[0];

  ///Array de ponteiros:
  int *pvet[10]; //Cada posição desse array é um ponteiro: Ou seja, cada posição pode guardar um endereço:

	return 0;
}
