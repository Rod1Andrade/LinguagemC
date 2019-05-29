#include <stdio.h>
#include <stdlib.h>

/**
 * Quando usar o Union: 
 * 
 * Quanto tiver variáveis que não vão ser
 * usadas ao mesmo tempo.
 *
 * */

//Área de Unions
union tipoUnion
{
  short int x;
  unsigned char c;
};

//Área de Structs
struct tipoStruct
{
  short int x;
  unsigned char c;
};

int main(int argv, char *argc[])
{
  //Declaração de uma variável union
  union tipoUnion t;

  //Declaração de uma variável struct
  struct tipoStruct s;

  /* Pode se acessar cada campo utilizando o operador de (ponto) "." **/
  t.x = 10;
  t.c = 'C';

  //Principal diferença entre Union e Struct, está na alocação de memória.
  
  //Union reserva a memória do maior
  printf("Union:  %lu bytes \t%lu bits\n", sizeof(t), (sizeof(t) * 8));
  
  //Struct aloca memória para todos os campos
  printf("Struct: %lu bytes \t%lu bits\n", sizeof(s), (sizeof(s) * 8));

  return 0;
}
