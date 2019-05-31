/**
 * Faça um programa para ler o nome e a idade de dois famosos e depois escrever o
 * nome do famoso mais velho ou se as idades são iguais. O programa deve parar de ler
 * os dados se for digitado fim(maiúsculo ou minúsculo) no nome
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Área de structs: 
typedef struct 
{
  char Nome[40];
  short Idade;

} pessoa;

int main(int argv, char *argc[])
{
  
  setlocale(LC_ALL, "Portuguese");

  //Intanciando na memória um vetor de pessoa.
  pessoa Pessoa[2];
  
  //Indice para controlar o vetor:
  short indice = 0; 

  while(1)
  {
    printf("Nome: ");
    fgets(Pessoa[indice].Nome, 40, stdin);

    Pessoa[indice].Nome[strlen(Pessoa[indice].Nome) - 1] = '\0';

    //Critério de parada do looping:
    if(strcasecmp(Pessoa[indice].Nome, "fim") == 0)
        break;

    printf("Idade: ");
    scanf("%hd", &Pessoa[indice].Idade);

    indice++;

    if(indice == 2) 
    {
      //Reiniciando o valor do Indice:
      indice = 0;

      if(Pessoa[0].Idade > Pessoa[1].Idade)
      {
        printf("%s é mais velho que %s\n", Pessoa[0].Nome, Pessoa[1].Nome);
      }
      else if(Pessoa[1].Idade > Pessoa[0].Idade)
      {
        printf("%s é mais velho que %s\n", Pessoa[1].Nome, Pessoa[0].Nome);
      }
      else
      {
        printf("%s e %s têm a mesma idade\n", Pessoa[0].Nome, Pessoa[1].Nome);
      }
    }//Fim if

    setbuf(stdin, NULL);
  }

  printf("Programa encerrado\n");
  
  return 0;
}
