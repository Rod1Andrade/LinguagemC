/**
 * Faça um programa para ler os primeiros nomes de uma pessoa na variável
 * PrimeirosNomes e último sobrenome de uma pessoa na variável UltimoNome. Depois
 * o programa deverá concatenar na variável NomePassaporte as seguintes informações:
 * o último sobrenome, com letras maiúsculas, uma vírgula e os primeiros nomes, com
 * letras minúsculas. Depois o programa deve solicitar que seja informado novamente os
 * dados do próximo nome, até que seja digitado fim  para terminar. O programa deve
 * parar de ler os dados se for digitado fim(maiúsculo ou minúsculo).
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Área de estrutura: 
typedef struct 
{
  char PrimeirosNomes[40];
  char UltimoNome[40];
} pessoa;

void strToUpper(char *str);
void strToLower(char *str);

int main(int argv, char *argc[])
{
  //Instância de Pessoa
  pessoa Pessoa;

  while(1)
  {

    //Variavel que será concatenada:
    char NomePassaporte[50] = "";  
    printf("Primeiros Nomes: ");  
    fgets(Pessoa.PrimeirosNomes, 40, stdin);

    printf("Último Nome: ");
    fgets(Pessoa.UltimoNome, 40, stdin);
    
    //Retirando o caracter de \n
    Pessoa.PrimeirosNomes[strlen(Pessoa.PrimeirosNomes) -1] = '\0';
    Pessoa.UltimoNome[strlen(Pessoa.UltimoNome) -1] = '\0';

    //Mudando o case dos nomes: 
    strToLower(Pessoa.PrimeirosNomes);
    strToUpper(Pessoa.UltimoNome);

    if(strcasecmp(Pessoa.UltimoNome, "fim") == 0)
      break;

    strcat(NomePassaporte, Pessoa.UltimoNome);
    strcat(NomePassaporte, ", ");
    strcat(NomePassaporte, Pessoa.PrimeirosNomes);

    printf("Nome Passaporte: %s\n", NomePassaporte);

    setbuf(stdin, NULL);
  }
  return 0;
}

//Minha função de strToUpper
void strToUpper(char *str)
{
  char aux;
  for(int i = 0; str[i] != '\0'; i++)
  {
    aux = toupper(str[i]); 
    str[i] = aux; 
  }
}

//Minha função de strToLower
void strToLower(char *str)
{
  char aux;
  for(int i = 0; str[i] != '\0'; i++)
  {
    aux = tolower(str[i]);
    str[i] = aux;
  }
}
