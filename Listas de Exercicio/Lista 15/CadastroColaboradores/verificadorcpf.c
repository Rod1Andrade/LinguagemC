/** MY HEADER FILE */
#include "verificadorcpf.h"

/** API DA LINGUAGEM C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///IMPLEMENTAÇÂO DA FUNÇÃO VERIFICACPF
/// @author: Rodrigo Andrade
/// @param char * n
/// @return 0 em caso de um CPF INVÁLIDO
/// @return 1 em caso de um CPF VÁLIDO
int verificaCPF(char *n)
{
  if(strlen(n) < 11)
    return 0; //CPF INVÁLIDO

  int vetor[11];

  //Váriaveis para verificação do Digito:
  int Digito1 = 0;
  int Digito2 = 0;
  int Count = 10;
  int conjuntoInvalido[9][11] =
  {
    {1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,2,2,2},
    {3,3,3,3,3,3,3,3,3,3,3},
    {4,4,4,4,4,4,4,4,4,4,4},
    {5,5,5,5,5,5,5,5,5,5,5},
    {6,6,6,6,6,6,6,6,6,6,6},
    {7,7,7,7,7,7,7,7,7,7,7},
    {8,8,8,8,8,8,8,8,8,8,8},
    {9,9,9,9,9,9,9,9,9,9,9}
  };

  ///Converte cada caraceter da tabela ascii para um correspontende inteiro.
  for(int i = 0; i < 11; i++)
  {
    vetor[i] = n[i];
    switch(vetor[i])
    {
      case 48:
        vetor[i] = 0;
      break;
      case 49:
        vetor[i] = 1;
      break;
      case 50:
        vetor[i] = 2;
      break;
      case 51:
        vetor[i] = 3;
      break;
      case 52:
        vetor[i] = 4;
      break;
      case 53:
        vetor[i] = 5;
      break;
      case 54:
        vetor[i] = 6;
      break;
      case 55:
        vetor[i] = 7;
      break;
      case 56:
        vetor[i] = 8;
      break;
      case 57:
        vetor[i] = 9;
      break;
    }
  }

  //Caso de descarte imediato:
  int contadorIguais = 0;
  for(int i = 0; i < 9; i++)
  {
    for(int j = 0; j < 11; j++)
    {
      if(vetor[j] == conjuntoInvalido[i][j])
      {
        contadorIguais++;
      }//Fim if
    }//Fim for interno
  }//Fim for externo

  //Se o contador der 11 digitos iguais, deve retorna 0
  if(contadorIguais == 11)
    return 0; //CPF Inválido

  //Somatório do Digito1
  for(int i = 0; i < 9; i++)
    Digito1 += (vetor[i] * Count--);

  //Resto da divisão do digito por 11
  Digito1 %= 11;
  Digito1 = 11 - Digito1;

  //Se o digito for maior que 9, deve receber 0, caso contrário mantém o valor;
  if(Digito1 > 9)
    Digito1 = 0;

  //Somátorio do Digito Verificador 2
  Count = 11;
  for(int i = 0; i < 10; i++)
    Digito2 += (vetor[i] * Count--);

  //Segue de maneira analoga a verificação dos digitor:
  Digito2 %= 11;
  Digito2 = 11 - Digito2;
  if(Digito2 > 9)
    Digito2 = 0;


  if(Digito1 != vetor[9] && Digito2 != vetor[10])
    return 0; //Caso do cpf inválido
  else
    return 1; //Caso do cpf válido
}//Fim da função verificaCPF(char *n);
