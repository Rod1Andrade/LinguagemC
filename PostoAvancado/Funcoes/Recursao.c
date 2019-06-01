/*
 * Uma função pode, inclusive, 
 * chamar a si própria. A isso chamamos
 * recursividade.
 *
 * **/

#include <stdio.h>
#include <stdlib.h>

//Função recursiva para o cálculo fatorial: 
int fatorial(int n)
{
  if(n == 0)
    return 1;
  else
    return n * fatorial(n-1);
}

int main(void)
{
  
  printf("Fatorial: %d", fatorial(5));
  return 0;
}
