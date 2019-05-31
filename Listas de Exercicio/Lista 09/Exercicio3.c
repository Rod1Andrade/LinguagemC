#include <stdio.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  
  int Numero;
  do
  {
    scanf("%d", &Numero);
  }
  while(Numero != 0);
  printf("Saiu do Loop");

  printf("\n");
  return 0;
}
