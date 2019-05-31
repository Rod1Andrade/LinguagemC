#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, "Portuguese");
  
  //Aloca o espaço de memória para variaveis inteiras.
  int x;

  //Coloca o valor '10' no espaço de memória alocado.
  x = 10;

  //Ponteiro para valor inteiro: 
  int *ponteiro;

  //Ponteiro aponta para o endereço de memória da variavel inteira x
  ponteiro = &x;

  printf("Endereço de int x = %p\n", &x);
  printf("Endereço de de x no ponteiro = %p\n", ponteiro);
  printf("Endereço de ponteiro = %p\n", &ponteiro);

  printf("\n");

  printf("Valor de int x = %d\n", x);
  printf("Valor do ponteiro p para x = %d\n", *ponteiro);
  return 0;
}
