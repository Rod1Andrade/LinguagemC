/*
 * @author: Rodrigo Andrade
 *
 * Exercício 2: Faça um programa para ler o salário bruto de uma pessoa e escrever o valor que
 * será desconto de INSS, de Imposto de Renda, o total de descontos, o percentual dos
 * descontos e o salário líquido da pessoa.
 *
 * **/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Parametrização das funções:
float INSS(float SalarioBruto);
float ImpostoRenda(float SalarioBruto, float INSS);
float SalarioLiquido(float SalarioBruto, float INSS, float ImpostoRenda);

int main(int argv, char *argc[])
{
  
  setlocale(LC_ALL, "Portuguese");
  float SalarioBruto;

  printf("Salário Bruto: ");
  scanf("%f", &SalarioBruto);

  float Inss = INSS(SalarioBruto);
  float Impo = ImpostoRenda(SalarioBruto, Inss);
  float SalarioL = SalarioLiquido(SalarioBruto, Inss, Impo);

  float TotalDesconto = SalarioBruto-SalarioL;
  float Porcentagem =  (TotalDesconto * 100) / SalarioBruto; 

  printf("INSS: %.2f\n", Inss);
  printf("Imposto de Renda: R$ %.2f\n", Impo);
  printf("Total dos Descontos: R$ %.2f\n", TotalDesconto);
  printf("Percentual dos Descontos: %.1f%%\n", Porcentagem);
  printf("Salário Líquido: R$ %.2f\n", SalarioL);

  return 0;

}


/**
 * @param SalarioBruto
 * return cálculo Imposto de Renda
 * Função para calcular INSS:
 * - Até 1.751,81 a aliquota de desconto é 8%
 * - De 1.751,82 até 2.919,72 a alíquota de desconto é de 9%
 * - De 2.919,73 até 5.839,45 a alíquota de desconto é de 11%
 * - Acima de 5.839,45 o desconto é de R$ 642,34 invariavelmete.
 *
 * */

float INSS(float SalarioBruto)
{
  const float CONSTANTE = 642.34;
  if(SalarioBruto <= 1751.81)
    return SalarioBruto * 0.08;
  else
    if(SalarioBruto <= 2919.72)
     return SalarioBruto * 0.09;
  else 
    if(SalarioBruto <= 5839.45)
      return SalarioBruto * 0.11;
  else 
    return CONSTANTE;
}

/**
 * @param SalarioBruto, INSS
 * return Cálculo Imposto de Renda
 *
 * IMPOSTO DE REDA = [(Salário bruto - dependentes - INSS) X alíquota] - dedução
 * Até R$1.903,98	isento	R$000,00
 * De R$1.903,99 até R$2.826,65	7,5%	R$142,80
 * De R$2.826,66 até R$3.751,05	15%	R$354,80
 * De R$3.751,06 até R$4.664,68	22,5%	R$636,13
 * Acima de R$4.664,68	27,5%	R$869,36
 * */
float ImpostoRenda(float SalarioBruto, float INSS)
{
  if(SalarioBruto <= 1903.98)
    return 0;  
  else if(SalarioBruto <= 2826.65)
      return ((SalarioBruto - INSS) * 0.75) - 142.80;
  elseif(SalarioBruto <= 3751.05)
      return ((SalarioBruto - INSS) * 0.15) - 354.80;
  else if(SalarioBruto <= 4664.68)
      return ((SalarioBruto - INSS) * 0.225) - 636.13;
  else 
    return ((SalarioBruto - INSS) * 0.275) - 869.36;
}

/**
 * @param SalarioBruto, INSS, ImpostoRenda
 * return SalarioLiquido
 *
 * */
float SalarioLiquido(float SalarioBruto, float INSS, float ImpostoRenda)
{
  if(SalarioBruto == 0)
    printf("Error, entrada Invalida\n");
  else
    return SalarioBruto - INSS - ImpostoRenda;
}

