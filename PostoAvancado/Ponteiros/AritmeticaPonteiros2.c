#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  int x = 1, *px, *py;

  px = py = &x;
  
  //Valor de x e endereço de px
  printf("x = %d, px = %p\n", *px, px);
  
  //Lembrando que isso é diferente de *(px + 1)
  int y = *px + 1;

  printf("x = %d, y = %d, px = %p\n", *px, y, px);

  //*(px + 1) está incrementando +1 no endereço de px
  y = *(px + 1);

  printf("y = %d\n", y);

  return 0;
} 
