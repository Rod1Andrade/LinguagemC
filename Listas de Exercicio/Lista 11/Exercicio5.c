#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  
  int Numero, Soma = 0; 
  printf("Digite números positivos para somar ou um número negativo para finalizar: \n"); 
  do
  {
    scanf("%d", &Numero); 

    if(Numero > 0)
      Soma += Numero;

  }while(Numero >= 0);
  
  if(Soma != 0)
    printf("Soma dos números Positivos: %d\n", Soma);
  else
    printf("Nenhum número Positivo foi digitador\n"); 

  return 0;
}
