#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

///Cálculo da média e do desvio padrão de um vetor:
int funcao(float *vetor, int tamanho, float *media, float *desvio)
{
  setlocale(LC_ALL, "Portuguese");

  if(media == NULL || desvio == NULL)
    return 0;

  *media = 0.0;
  for(int i = 0; i < tamanho; i++)
    *media += vetor[i]/tamanho;

  *desvio = 0.0;

  for(int i = 0; i < tamanho; i++)
    *desvio += pow((vetor[i] - *media), 2)/tamanho;

  *desvio = sqrt(*desvio);

  return 1;

}

int main(int argc, char *argv[])
{
  float vetor[3] = {1.55, 1.70, 1.80}; 
  float desvio, media;

  funcao(vetor, 3, &media, &desvio);
  printf("Média: %.2f\n", media);
  printf("Desvio Padrão: %.4f\n", desvio);
  return 0;
}
