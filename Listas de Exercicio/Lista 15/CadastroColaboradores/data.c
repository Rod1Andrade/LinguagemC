/**
* @author: Rodrigo Andrade
* 13/jun/2019
*
*/
/**MY HEADER FILE*/
#include "data.h"

/**APIS DA LINGUAGEM C*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**VARIÁVEIS GLOBAIS**/
int vetor[3]; //Armazena as data dia, mes e ano, nas posições 0, 1, 2;

int validaData(char *Data)
{

  //Verifica o tamanho da data:
  if(strlen(Data) != 10)
  {
    printf("\nMensagem de erro: Formato da data deve ser dd/mm/yyyy.\n");
    return 0;
  }//Fim do if
  for(int i = 0; Data[i] != '\0'; i++)
  {
    if(Data[i] != '/' && !isdigit(Data[i]))
    {
      return 0;
    }//Fim do if
  }//Fim do for

  //Separo os caracteres de / e coloca os numeros em um vetor, convetendo-os para inteiro:
  char *token;

  token = strtok(Data, "/");
  vetor[0] = atoi(token);

  for(int i = 1; i < 3; i++)
  {
    token = strtok('\0', "/");
    vetor[i] = atoi(token);
  }

  //Depos da separação das variaveis e conversão, aplica-se a lógica de validação
  int dia, mes, ano, bissex;
  dia = vetor[0];
  mes = vetor[1];
  ano = vetor[2];

  bissex = bissexto(ano);

  //Verifica o padrão de mesês
  if(mes < 1 && mes > 12)
  {
    ///Mensagem de erro REGRA DE NEGÓCIO
    printf("\nMensagem de erro: Mês de nascimento inválido.\n");
    return 0;
  }
  int conjuntoMeses[] = {1, 3, 5, 7, 8, 10, 12};
  int conjuntoMeses2[] = {2, 4, 6, 9, 11};

  //Verificação do ano bissexto:
  if(mes == 2)
  {
    if(bissex == 1)
      if(dia > 0 && dia < 30)
        return 1;
      else
      {
        printf("\nMensagem de erro: Dia de nascimento inválido\n");///REGRA DE NEGÓCIO
        return 0;
      }
    else
      if(dia > 0 && dia < 29)
        return 1;
      else
      {
        printf("\nMensagem de erro: Dia de nascimento inválido\n");///REGRA DE NEGÓCIO
        return 0;
      }
  }

  //Verificação dos meses que vai até 31:
  for(int i = 0; i < 7; i++)
  {
    if(mes == conjuntoMeses[i])
    {
      if(dia >= 1 && dia <= 31)
      {
        return 1;
      }
      else
      {
        printf("\nMensagem de erro: Dia de nascimento inválido\n");
        return 0;
      }
      break;
    }
    ///Mensagem da: REGRA DE NEGÓCIO

  }

  //Verificação dos meses que vai até 30:
  for(int i = 0; i < 5; i++)
  {
    if(mes == conjuntoMeses2[i])
    {
      if(dia >= 1 && dia <= 30)
      {
        return 1;
      }
      ///Mensagem da: REGRA DE NEGÓCIO
      else
      {
        printf("\nMensagem de erro: Dia de nascimento inválido\n");
        return 0;
      }
      break;
    }
  }

  return 0;
}

//Função para cálculo do ano bissexto:
int bissexto(int ano)
{
  if(ano%4 == 0 || ano%400 == 0 && ano%100 != 0)
    return 1;
  return 0;
}

/**REGRA DE NEGÓCIO, SE FOR MENOR DE 18 ANOS E MAIOR QUE 80, NÃO PODE ENTRAR NO CADASTRO: */
int idadeValida(char *Data)
{
  //Depos da separação das variaveis e conversão, aplica-se a lógica de validação
  int ano = vetor[2];

  if((2019 - ano) >= 18 && (2019 - ano) <= 80)
  {
    return 1;
  }
  else
  {
    printf("\nMensagem de erro: Ano de nascimento inválido.\n");
    setbuf(stdin, NULL);
    return 0;
  }
}
 /*******************************************************************************/
