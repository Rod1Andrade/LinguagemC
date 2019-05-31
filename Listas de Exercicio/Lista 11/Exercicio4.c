#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, NULL); 

  //Observação Pessoal: Utilzando o (For) parece ser mais optimizado.
  
  int Fatorial = 1, Count = 1, Numero;

  printf("Digite um número para calcular o fatorial: ");
  scanf("%d", &Numero);

  do
  {
    Fatorial *= Count++;
  }while(Count <= Numero);

  printf("Fatorial: %d\n", Fatorial);
  
  return 0;
}
