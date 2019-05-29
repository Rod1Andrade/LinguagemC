#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  int size;
  printf("Digite a quantidade de numeros que deseja entrar: ");
  scanf("%d", &size);

  //inicia o tamanho do vetor com o tamanho digitado pelo usuario
  int vetor[size]; 

  //Adciona valores dentro do vetor
  for(int i = 0; i < size; i++)
  {
    printf("Entre com o #%d valor: ", i+1);
    scanf("%d", &vetor[i]);
  }

  //Vou considerar o maior número a primeira posição do vetor
  int maior = vetor[0];

  //Iterar o vetor comparando os valores com a variavel maior
  for(int i = 1; i < (sizeof(vetor) / sizeof(int)); i++)
    if(vetor[i] > maior)
      maior = vetor[i];

  printf("Maior valor: %d\n", maior);
 
  return 0;
}
