/**
 * Fazer um programa para cálcular todas as combinações possíveis
 * de jogos da mega-sena:
 *
 * Jogadas Possives:
 * - 6
 * - 7
 * - 8
 * - 9
 * - 10
 *
 * Quantidade de números sorteados: 6
 * 
 * */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  /**
   * C n,p = 60! / 6!(60-6)!
   * C 60,6 = 60! / 6! 54!
   * C 60,6 = 60 * 59 * 58 * 57 * 56 * 55 / 6!
   *
   * */

  printf("A Mege-sena é um combinação de 6 números, em uma cartela contendo de 1 a 60.\n");
  printf("As cartelas podem ser preenchidas de 5 formas diferentes, aumentando as chances de ganhar: \n\n");
  printf("Quantidade de Números possiveis a serem preenchidos:\n");
  printf("- 6\n- 7\n- 8\n- 9\n- 10\n\n");

  short QuantidadeJogada;
  do
  {
    printf("Entre com a Quantidade jogada: "); 
    scanf("%hd", &QuantidadeJogada);
  }while(QuantidadeJogada < 6 || QuantidadeJogada > 10);

  printf("\n\n");

  //Variáveis que armazenam os cálculos: 
  long n = 1;
  int p = 1;
  long Combinacao;

  //Fatorial de 60
  for(int i = 60; i > (60-6); i--)
    n *= (long)i;

  //Fatorial da quantidade jogada
  for(int i = 1; i <= 6; i++)
    p *= i;

 // printf("N: %ld\n", n);
 // printf("P: %d\n", p);


  //C 60,6 = 60! / 6!(60-6)!
  Combinacao = n / p;

  if(QuantidadeJogada == 6)
  {
    printf("Combinações possíveis: 1/%ld\n", Combinacao);
  }
  else if(QuantidadeJogada == 7)
  {
    n = 1;
    p = 1;
    for(int i = QuantidadeJogada; i > (QuantidadeJogada-6); i--)
      n *= (long) i; 
    for(int i = 2; i <= 6; i++)
      p *= i;

    printf("Chance é de: %ld / %ld\n", (n/p), Combinacao);
  }
  else if(QuantidadeJogada == 8)
  {
    n = 1;
    p = 1;
    for(int i = QuantidadeJogada; i > (QuantidadeJogada-6); i--)
      n *= (long) i; 
    for(int i = 2; i <= 6; i++)
      p *= i;

    printf("Chance é de: %ld / %ld\n", (n/p), Combinacao);

  }
  else if(QuantidadeJogada == 9)
  {
    n = 1;
    p = 1;
    for(int i = QuantidadeJogada; i > (QuantidadeJogada-6); i--)
      n *= (long) i; 
    for(int i = 2; i <= 6; i++)
      p *= i;

    printf("Chance é de: %ld / %ld\n", (n/p), Combinacao);

  }
  else
  {
    n = 1;
    p = 1;
    for(int i = 10; i > (4); i--)
      n *= (long) i; 
    for(int i = 2; i <= 6; i++)
      p *= i;

    printf("Chance é de: %ld / %ld\n", (n/p), Combinacao);
  } 
  return 0;
}
