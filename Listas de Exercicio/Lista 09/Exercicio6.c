#include <stdio.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  
  float Numero, Soma;
  scanf("%f", &Numero);

  while(Numero != 0)
  {
    Soma += Numero;
    scanf("%f", &Numero);
  }
  
  printf("Soma: %.2f", Soma);

  printf("\n");
  return 0;
}
