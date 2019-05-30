#include <stdio.h>
#include <stdlib.h>

void adciona(int *n)
{
  (*n)++;
  printf("Dentro da funcao: n = %d\n", *n);
}

int main(void)
{
  
  /**
   * Passagem por refência:
   * o endereço de onde o dado está armazenado na memória
   * é passado para a função. Através de um ponteiro para o tipo referente.
   *
   * Assim, a função pode modificar o valor do parâmetro. (!IMPORTANTE)
   *
   * */
  int x = 100;
  printf("Antes da chamada da função por referência: %d\n", x);

  adciona(&x);

  printf("Depois da chamada da função por referência: %d\n", x);


  return 0;
}
