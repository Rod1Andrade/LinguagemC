#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  //Somando valores de um vetor:
  int lista[] = {10, 5, 5, 10, 10};
  int soma = 0;
  long tamanho = sizeof(lista) / sizeof(int);
  
  printf("Tamanho vetor: %lu\n", tamanho);
  
  for(int i = 0; i < tamanho; i++)
    soma += lista[i];

  printf("Soma: %d\n", soma);

  soma = 0;

  //Somado os valores de uma matriz: 
  int matriz[3][3] = {
    {7, 8, 9},
    {4, 5, 6},
    {1, 2, 3}
  };

  for(int linha = 0; linha < 3; linha++)
  {
    for(int coluna = 0; coluna < 3; coluna++)
    {
      soma += matriz[linha][coluna];
    }
  }

  printf("Soma: %d\n", soma);

  return 0;
}
