#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");
  
  //Múltiplos entre 5 e 100
  printf("Números Múltiplos de 5 entre 0 e 100: ");
  for(int i = 5; i <= 100; i += 5)
  {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}
