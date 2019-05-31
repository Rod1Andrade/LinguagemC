#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  int Numero, Count = 1, Aux;

  printf("Digite um número: ");
  scanf("%d", &Numero);
  
  //Variável para auxiliar no Looping
  Aux = Numero;

  while(Count <= Numero)
  {
    printf("%d %d\n", Aux--, Count++); 
    
  }

  return 0;
}
