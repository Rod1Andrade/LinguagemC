/**MY HEADER FILE*/
#include "DefaultAPISystem.h"

/**LIBRARY LANGUAGE C*/
#include <stdio.h>

void menuAplicacao()
{
  printf("\nMENU\n");
  printf("----------\n");

  printf("1 - Consultar\n");
  printf("2 - Editar\n");
  printf("3 - Adcionar Colaborador\n");
  printf("4 - Remover Colaborador\n");
  printf("5 - Visualizar Colaboradores\n");
  printf("0 - Finalizar Sistema\n");
}

void menuDepartamentos()
{
  printf("\nDEPARTAMENTO\n");
  printf("-------------------\n");
  printf("Indústria\n");
  printf("Limpeza\n");
  printf("Administrativo\n");
  printf("Transporte\n");
  printf("Segurança\n");

}

/**
* @author: Rodrigo Andrade
* @param opcao
* @param endereço de memória da string
* Função, atribuirs os valores correspondete de cada área para a váriavel destino
*/
void atribuicaoDPT(char opcao, char *destino)
{
  switch(opcao)
  {
    case 'I':
      strcpy(destino, "Industria");
    break;

    case 'L':
      strcpy(destino, "Limpeza");
    break;

    case 'A':
      strcpy(destino, "Administrativo");
    break;

    case 'T':
      strcpy(destino, "Transporte");
    break;

    case 'S':
      strcpy(destino, "Seguranca");
    break;

    default:
      printf("Erro\n");
    break;
  }
}

void menuEscolaridade()
{
  printf("\nESCOLARIDADE\n");
  printf("-------------------\n");
  printf("Ensino Médio\n");
  printf("Graduação\n");
  //printf("Especialização\n");
  printf("Mestrado\n");
  printf("Doutorado\n");
}

/**
* @author: Rodrigo Andrade
* @param opcao
* @param endereço de memória da string
* Função, atribuir os valores correspondete de cada área para a váriavel destino
*/
void atribuicaoEscolaridade(char opcao, char *destino)
{
  switch(opcao)
  {
    case 'E':
      strcpy(destino, "Ensino Medio");
    break;

    case 'G':
      strcpy(destino, "Graduacao");
    break;

    //case 'E':
     // strcpy(destino, "Especializacao");
    //break;

    case 'M':
      strcpy(destino, "Mestrado");
    break;

    case 'D':
      strcpy(destino, "Doutorado");
    break;

    default:
      printf("Erro\n");
    break;
  }
}

