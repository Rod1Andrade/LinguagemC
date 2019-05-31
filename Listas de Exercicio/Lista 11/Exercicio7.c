#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, NULL);
  int Numero; 
  char Sinal;

  while(1)
  {
    setbuf(stdin, NULL);
    //Contador para controlar os Loopings dentros de cada swtich
    int Count = 0;

    printf("Digite um número que deseja obter a tabuada ou -1 para sair: ");
    scanf("%d", &Numero); 

    if(Numero == -1)
      break;

    setbuf(stdin, NULL);

    printf("Digite o sinal para efetur a tabuada: ");
    scanf("%c", &Sinal);

    switch(Sinal)
    {
      case '+':
        do
        {
          int Soma = Numero + Count;
          printf("%d %c %d = %d\n", Numero, Sinal, Count, Soma); 
          Count++;
        }while(Count <= 10);
        break;

      case '-':
        do
        {
          int Sub = Numero - Count;
          printf("%d %c %d = %d\n", Numero, Sinal, Count, Sub); 
          Count++;
        }while(Count <= 10);
        break;

      case '*':
        do
        {
          int Produto = Numero * Count;
          printf("%d %c %d = %d\n", Numero, Sinal, Count, Produto); 
          Count++;
        }while(Count <= 10);
        break;

      case '/':
        do
        {
          float Div = Numero + Count;
          printf("%d %c %d = %.1f\n", Numero, Sinal, Count, Div); 
          Count++;
        }while(Count <= 10);
        break;

      default:
        printf("Sinal Inválido!\n"); 
        break;  
    }
  }

  return 0;
}
