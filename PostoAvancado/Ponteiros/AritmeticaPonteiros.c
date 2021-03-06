#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{

  //Pode-se alterar o valor da variavel raiz utilizando um ponteiro: 
  char x, *px, *pc;
  px = &x;
  *px = 3;


  //Valor inicial:
  printf("x = %d\n", x);

  //Incrementando o valor de x
  *px = *px + 1;
  printf("x = %d\n", x);

  (*px)++;
  printf("x = %d\n", x);

  //OBSERVAÇÃO
  /*
   * (*px)++ é diferente de *px++
   * Em um você incrementa o valor contido na variavel x
   * No segundo caso, você incrementa em +1 o endereço de memória contido no ponteiro
   * exemplo: 
  **/

  printf("Ender px = %d\n", px);

  *px++;

  printf("Ender px = %d\n\n", px);

  pc = px;

  //Ponteiros podem ser comparados:
  if(px == pc)
    printf("Ponteiros apontam para o mesmo endereço.\n");
  else
    printf("Ponteiros apotam para um endereço diferente.\n");

  return 0;
}
