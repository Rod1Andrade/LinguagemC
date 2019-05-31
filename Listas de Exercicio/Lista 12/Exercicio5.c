#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  //Faça um programa que leia o número de termos da série (N) e imprima o valor de H, sendo
  //H = 1 + 1⁄2 + 1⁄3 + 1⁄4 + ... + 1/N
  
  float H = 0; 
  int N;

  printf("Digite o Número de Termos: ");
  scanf("%d", &N);
  
  setbuf(stdin, NULL);

  for(int i = 1; i <= N; i++)
  {
    H += (1.0 / (float)i); 
    printf("%f\n", H);
  }

  printf("H: %.2f\n", H);


  return 0;
}
