#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

int main(int argv, char *argc[])
{
  
  setlocale(LC_ALL, NULL);

  int Quantidade, Numero, Menor = INT_MAX;

  printf("Digite a quantidade de números que desejar digtar: "); 
  scanf("%d", &Quantidade); 
  printf("Digite %d números: \n", Quantidade);
  do{
    
    setbuf(stdin, NULL);
    scanf("%d", &Numero);

    if(Numero < Menor)
      Menor = Numero;

    Quantidade--;
  }while(Quantidade > 0);

  printf("Menor número é: %d\n", Menor);

  return 0;
}
