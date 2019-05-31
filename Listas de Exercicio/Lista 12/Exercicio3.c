#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  //Desenvolva um programa que leia 15 números inteiros e imprima, ao final, a soma 
  //dos positivos e a quantidade de números negativos digitados.

  int SomaPositivos = 0, ContadorNegativos = 0, Numero;

  for(int i = 0; i < 15; i++)
  {
    scanf("%d", &Numero);

    if(Numero > 0)
    {
      SomaPositivos += Numero;
    }
    else
    {
      ContadorNegativos++;
    }
  }

  printf("Soma dos Positivos: %d\n", SomaPositivos);
  printf("Quantidade de Negativos: %d\n", ContadorNegativos); 
  
  return 0;
}
