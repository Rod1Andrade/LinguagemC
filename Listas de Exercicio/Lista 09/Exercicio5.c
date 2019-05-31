#include <stdio.h>
#include <locale.h>

int main(int argv, char *argc[])
{
 
  float ValorUnitario, ValorTotal = 0, Media;
  int Quantidade = 0, Contador = 0;

  while(1)
  {
    setbuf(stdin, NULL);
    printf("Quantidade: ");  
    scanf("%d", &Quantidade);
    
    Contador += Quantidade; //Armazena a Quantidade para calcular a média.

    if(Quantidade == 0)
      break;

    printf("Preco: ");
    scanf("%f", &ValorUnitario);

    ValorTotal += Quantidade * ValorUnitario;
  }
  
  Media = ValorTotal / Contador;

  printf("Valor total: %.2f\n", ValorTotal);
  printf("Média compras: %.2f\n", Media);

  printf("\n");
  return 0;
}
