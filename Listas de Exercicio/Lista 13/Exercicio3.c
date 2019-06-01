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

  //Variavel igual se o valor for igual a 1, significa que as idades são iguais:
  int igual = 0;

  const int tam = 2;

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

    //Index vai sempre retornar o Maior:
    int index, Padrao = 0;

    if(indice == tam) 
    {
      
      int MaiorIdade = Pessoa[0].Idade;

      for(index = 1; index < tam; index++)
      {
        if(Pessoa[index].Idade > MaiorIdade)
          MaiorIdade = Pessoa[index].Idade;
        else
          if(Pessoa[index].Idade == MaiorIdade)
            igual = 1;
          else
            //Indice 0 é o maior
            Padrao = 1;
      }

      //Reiniciando o valor do Indice:
      indice = 0;


    //Imprimir resultados: 
    if(igual == 1)
    {
      printf("%s e ", Pessoa[0].Nome);
      for(int i = 1; i <= tam-1; i++)
      {
        if((tam-1) > 2)
          printf("%s, ", Pessoa[i].Nome);
        else
          printf("%s", Pessoa[i].Nome);
      }
      printf(" tem a mesma idade.\n");
    }
    else
    {
      if(tam > 2)
        printf("%s tem a idade maior que todos.\n", Pessoa[index].Nome);
      else
        if(Padrao == 1)
          printf("%s é mais velho que %s\n", Pessoa[0].Nome, Pessoa[1].Nome);
        else
          printf("%s é mais velho que %s\n", Pessoa[1].Nome, Pessoa[0].Nome);
    }

    }//Fim if que verifica se o indice == 2
    setbuf(stdin, NULL);
  }

  printf("Programa encerrado\n");
  
  return 0;
}
