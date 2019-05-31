#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*************************** LÓGICA DE PROGRAMAÇÃO I *****************************
 * Professor: Joilson dos Reis Brito
 * Lista Número: 08
 * Nome do Autor: Rodrigo Moreira Pires de Andrade
 * Data divulgação: 30/04/2019
 * Enunciado: 
 * *******************************************************************************/

//Parametrização de funções: 

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, "Portuguese");

  const float PRECO_G = 4.22;
  const float PRECO_A = 3.49;

  printf("Tabela: | G = %.2f \t | \t A = %.2f\n", PRECO_G, PRECO_A);

  double QuantidadeCombustivel;
  float PrecoBruto;
  float TotalPagar;

  unsigned char Opcao;

  printf("Digite a quantidade de litros abastecidos: "); 
  scanf("%lf", &QuantidadeCombustivel);

  printf("Escolha o tipo de combustível ( 1 - Etanol; 2 - Gasolina): ");
  scanf("%d", &Opcao);

  printf("Quantidade Combustivel: %.2fL\n", QuantidadeCombustivel);

  switch(Opcao)
  {
    case 1:
      //Valor Bruto do Álcool (sem desconto)
      PrecoBruto = QuantidadeCombustivel * PRECO_A;
      printf("Preco Bruto: R$ %.2f.\n", PrecoBruto);

      if(QuantidadeCombustivel > 0 && QuantidadeCombustivel <= 20)
      {
        //Até 20 litros --> Desconto <- 3% (total = PrecoBruto - (PrecoBruto * 0.03)
        TotalPagar = PrecoBruto - (PrecoBruto * 0.03);
        printf("Total a pagar com 3%% de desconto: R$ %.2f.\n", TotalPagar);
      }//Fim do If   
      else
      {
        //Acima de 20 Litros --> Desconto <-- 5 % ( total = PrecoBruto - (PrecoBruto * 0.5)
        TotalPagar = PrecoBruto - (PrecoBruto * 0.05);
        printf("Total a pagar com 5%% de desconto: R$ %.2f.\n", TotalPagar);
      }//Fim do else
    break;
    case 2:
      //Valor Bruto da Gasolina (sem desconto)
      PrecoBruto = QuantidadeCombustivel * PRECO_G;
      printf("Preco Bruto: R$ %.2f.\n", PrecoBruto);

      if(QuantidadeCombustivel > 0 && QuantidadeCombustivel <= 20)
      {
        //Até 20 litros --> Desconto <- 4% (total = PrecoBruto - (PrecoBruto * 0.04)
        TotalPagar = PrecoBruto - (PrecoBruto * 0.04);
        printf("Total a pagar com 4%% de desconto:R$  %.2f.\n", TotalPagar);
      }//Fim do If   
      else
      {
        //Acima de 20 Litros --> Desconto <-- 6 % ( total = PrecoBruto - (PrecoBruto * 0.6)
        TotalPagar = PrecoBruto - (PrecoBruto * 0.06);
        printf("Total a pagar com 6%% de desconto: R$ %.2f.\n", TotalPagar);
      }//Fim do else
    break;
    default:
      printf("Tipo de combustivel invalido\n");
    break;
  }//Fim do switch

  return 0;
} 

