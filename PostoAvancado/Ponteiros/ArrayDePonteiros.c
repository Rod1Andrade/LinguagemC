#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  /**
   *  Também podemos declarar um 
   *  array de ponteiros.
   *
   *  Forma Geral: 
   *
   *  <tipo> *nome_array[tamanho];
   *
   * */

  //Array de 5 ponteiros
  int *vPonteiroInteiro[5]; 

  //Um vetor onde cada posição pode guardar um endereço de memória do tipo inteiro:
  int x = 10, y[2] = { 15, 20 };

  //Primeira posição do meu vetor de ponteiros recebe
  //o endereço do inteiro x;
  vPonteiroInteiro[0] = &x;

  //A segunda posição recebe o endereço do vetor de inteiro de 2 posições:
  vPonteiroInteiro[1] = y;

  printf("Endereço do ponteiro[0] = %p\n", vPonteiroInteiro[0]); //Endereço de X
  printf("Endereço do ponteiro[1] = %p\n", vPonteiroInteiro[1]); //Endereço de y[0]

  //Imprimindo valores nos quais o ponteiro de inteiro aponta:
  printf("Valor do ponteiro[0] = %d\n", *vPonteiroInteiro[0]); //Endereço de y[0]
  printf("Valor do ponteiro[1][0] = %d\n", vPonteiroInteiro[1][0]); //Endereço de y[0]

  return 0;
}

