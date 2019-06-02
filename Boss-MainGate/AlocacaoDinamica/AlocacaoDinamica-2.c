#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nome[30];
  char sexo;
  int idade;
  float altura;
}funcionario;

int main(void)
{
  
  //Operador sizeof();
  /**
   *
   * Alocar memória do tipo int é diferente 
   * de alocar memória para um tipo char:
   * - Tipos diferentes podem ter tamanhos diferentes na memória:
   *   Para isso temos o operador sizeof(); para se delimitar 
   *   quanto de memória será necessario reservar.
   *
   * */


  funcionario f;

  printf("Tamanhos: \n");
  printf("char: %zu byte\n", sizeof(char));
  printf("short: %zu bytes\n", sizeof(short));
  printf("int:  %zu bytes\n", sizeof(int));
  printf("long:  %zu bytes\n", sizeof(long));
  printf("float: %zu bytes\n", sizeof(float));
  printf("double: %zu bytes\n", sizeof(double));
  printf("Struct Funcionario: %zu bytes\n", sizeof(f));

  /**
   * O operador sizeof retorna o número de bytes necessários 
   * para alocar um único elemento de um determinado tipo de dado
   *
   * Forma geral: 
   * sizeof(<tipo>);
   *
   * */
  return 0;
}
