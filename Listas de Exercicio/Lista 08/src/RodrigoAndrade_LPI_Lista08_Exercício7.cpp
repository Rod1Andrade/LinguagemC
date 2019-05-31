#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
  setlocale(LC_ALL, "Portuguese");

  int QuantidadeFaltas; 

  printf("Quantidade de faltas: ");
  scanf("%d", &QuantidadeFaltas);

  float Porcentagem = (100 * QuantidadeFaltas) / 72;

  /*
    Se percentual de faltas > 25 escrever VOCE ESTA REPROVADO POR FALTA
    Se percentual de faltas = 25 escrever VOCE ESTA NO LIMITE DE FALTAS
    Se percentual de faltas = 0 escrever VOCE NAO TEM FALTA
    Se percentual de faltas <25 escrever VOCE TEM FALTAS MAS AINDA NÃO ESTA NO LIMITE
   * */

  if(Porcentagem > 25.0)
  {
    printf("VOCE ESTA REPROVADO POR FALTA\n"); 
  }
  else if(Porcentagem == 25.0)
  {
    printf("VOCE ESTA NO LIMITE DE FALTAS\n"); 
  }
  else if(Porcentagem > 0 && Porcentagem < 25.0)
  {
    printf("VOCE TEM FALTAS MAS AINDA NÃO ESTA NO LIMITE\n"); 
  }
  else
  {
    printf("VOCE NAO TEM FALTA\n"); 
  }

  return 0;
}
