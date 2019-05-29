#include <stdio.h>
#include <stdlib.h>

/*
 * Quando utilizar?
 *
 * 1º caso: Economia de memória.
 * Quando se tem muitas variáveis que não são utilizadas ao 
 * mesmo tempo. Faz total sentido usar Unions.
 *
 * 2º caso: Manipulação de bits
 *
 * **/

//Área Unions
union tipo
{
  short x;
  unsigned char c[2];
};

int main(int argv, char *argc[])
{ 
  union tipo u;
  printf("Tamanho Union: %lu bytes \t %lu bits\n\n", sizeof(u), (sizeof(u) * 8));

  u.x = 100;
  printf("%d\n", u.x);

  u.c[0] = 'L';
  u.c[1] = 'C';

  printf("%c \t %c", u.c[0], u.c[1]);
  return 0;
}
