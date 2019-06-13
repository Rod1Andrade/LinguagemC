/*
 * @author: Rodrigo Andrade
 * Validação de datas, anos bissexto e meses com 30 e 31.
 *
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int bissexto(int ano);
int validaData(char *Data);

int validaData(char *Data)
{
  
  //Verifica o tamanho da data: 
  if(strlen(Data) != 10)
  {
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
  int vetor[3];
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
    return 0;

  int conjuntoMeses[] = {1, 3, 5, 7, 8, 10, 12}; 
  int conjuntoMeses2[] = {2, 4, 6, 9, 11};

  //Verificação do ano bissexto:
  if(mes == 2)
  {
    if(bissex == 1)
      if(dia > 0 && dia < 30)
        return 1;
      else
        return 0;
    else
      if(dia > 0 && dia < 29)
        return 1;
      else
        return 0; 
  }

  //Verificação dos meses que vai até 31:
  for(int i = 0; i < 7; i++)
  {
    if(mes == conjuntoMeses[i])
    {
      if(dia >= 1 &&  dia <= 31)  
        return 1;
      break;
    }
  }

  //Verificação dos meses que vai até 30:
  for(int i = 0; i < 5; i++)
  {
    if(mes == conjuntoMeses2[i])
    {
      if(dia >= 1 && dia <= 30)
      {
        return 1;
        break;
      }
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

