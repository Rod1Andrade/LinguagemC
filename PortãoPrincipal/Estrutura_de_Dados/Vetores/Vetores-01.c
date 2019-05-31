#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  
  setlocale(LC_ALL, "Portuguese");
  const int Tamanho = 4;
  
  float Notas[Tamanho], Total = 0; 

  for(int i = 0; i < Tamanho; i++)
  {
    printf("Digite o valor #%d: ", i + 1);
    scanf("%f", &Notas[i]);
    Total += Notas[i];
  }

  printf("Média: %.2f\n", Total / Tamanho);

  return 0;
}
