#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*********************** LÓGICA DE PROGRAMAÇÃO ****************************
 * Professor: Joilson dos Reis Brito
 * Lista Número: 08
 * Nome do Autor: Rodrigo M.P Andrade
 * Data de divulgação: 30/04/19
 * Enunciado do Problema: 
 * *************************************************************************/

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, "Portuguese");

  const int FRANQUIA = 7;
  int Intervalo[3];
  float ContaPagar;

  float Consumo; 
  
  printf("Digite o consumo de água: ");
  scanf("%f", &Consumo);

  printf("\n");

  if(Consumo <= 10.0)
  {
    printf("7 Reais Assinatura Básica;\n");
    ContaPagar = FRANQUIA;  
  }//Fim if
  else if(Consumo > 10.0 && Consumo <= 30.0)
  {
    Intervalo[0] = (Consumo - 10);
    printf("7 Reais Assinatura Básica;\n");
    printf("%d reais pelo consumo no intervalo 11 a 30 m^3.\n", Intervalo[0]);
    ContaPagar = Intervalo[0] + FRANQUIA;
  }//Fim else if
  else if(Consumo > 30.0 && Consumo <= 100.0)
  {
    Intervalo[1] = (Consumo - 30) * 2;
    Intervalo[0] = (30 - 10); 
    printf("7 Reais Assinatura Básica;\n");
    printf("%d reais pelo consumo no intervalo 11 a 30 m^3.\n", Intervalo[0]);
    printf("%d reais pelo consumo no intervalo 31 a 100 m^3.\n", Intervalo[1]);
    ContaPagar = Intervalo[1] + Intervalo[0] + FRANQUIA;
  }//Fim else if
  else
  {
    Intervalo[2] = (Consumo - 100) * 5;
    Intervalo[1] = (100 - 30) * 2;
    Intervalo[0] = (30 - 10); 
    printf("7 Reais Assinatura Básica;\n");
    printf("%d reais pelo consumo no intervalo 11 a 30 m^3.\n", Intervalo[0]);
    printf("%d reais pelo consumo no intervalo 31 a 100 m^3.\n", Intervalo[1]);
    printf("%d reais pelo consumo no intervalo 101 a %.1f m^3.\n", Intervalo[2], Consumo);
    ContaPagar = Intervalo[2] + Intervalo[1] + Intervalo[0] + FRANQUIA;
  }//Fim else

  //Saida
  printf("\n");
  printf("Valor total da conta de água: %.2f\n", ContaPagar);

  //system("Pause");
  return 0;

