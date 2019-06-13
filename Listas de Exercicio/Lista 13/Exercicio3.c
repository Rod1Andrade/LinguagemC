
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

  //Tamanho vetor:
  const int tam = 2;

  //Instanciando na memória um vetor de pessoa.
  pessoa Pessoa[tam];

  //Vetor De pessoas velhas:
  pessoa PessoasVelhas[tam];
  
  //Indice para controlar o vetor:
  short indice = 0; 

  while(1)
  {
    //Iniciando todas as posições do vetor de PessoasVelhas como NULA:
    for(int i = 0; i < tam; i++)
    {
      strcpy(PessoasVelhas[i].Nome, "NULL");
      PessoasVelhas[i].Idade = 0;
    }

    printf("Nome: ");
    fgets(Pessoa[indice].Nome, 40, stdin);

    //Substituindo o caracter de \n pelo de \0
    Pessoa[indice].Nome[strlen(Pessoa[indice].Nome) - 1] = '\0';

    //Critério de parada do looping:
    if(strcasecmp(Pessoa[indice].Nome, "fim") == 0)
      break;

    printf("Idade: ");
    scanf("%hd", &Pessoa[indice].Idade);

    indice++;

    //Index vai sempre retornar o Maior:
    int index, Padrao = 0;

    //Variavel igual se o valor for igual a 1, significa que as idades são iguais:
    int igual = 0; 

    //Conta a quantidade de iguais
    int QuantidadeIgual = 0; 


    if(indice == tam) 
    {

      int MaiorIdade = Pessoa[0].Idade;

      for(index = 1; index < tam; index++)
      {
        if(Pessoa[index].Idade > MaiorIdade)
          MaiorIdade = Pessoa[index].Idade;
        else
          //O indice 0 é o maior
          Padrao = 1;
      }


      //Adciona as pessoas mais velha no vetor de PessoasVelhas.
      if(tam > 2)
      {
        for(int i = 0; i < tam; i++)
        {
          if(Pessoa[i].Idade == MaiorIdade)
          {
            strcpy(PessoasVelhas[i].Nome, Pessoa[i].Nome);
            PessoasVelhas[i].Idade = Pessoa[i].Idade;
            QuantidadeIgual++;
          }
        }

        //Verifica a quantide de pessoas quem te a mesma idade
        if(QuantidadeIgual >= 2)
        {
          for(int i = 0; i < tam; i++)
          {
            if(!strcmp(PessoasVelhas[i].Nome, "NULL") == 0)
            {
              printf("%s ", PessoasVelhas[i].Nome);
              if(QuantidadeIgual > 2 && i < tam-1)
                printf(", ");
            }
            else if(i == tam-2 && QuantidadeIgual <= 2)
              printf(" e ");
          }
          printf(" São mais velhos e tem a mesma idade.\n");
        }

        //Imprime o mais velho, caso não tenha idades iguais.
        else
        {
          for(int i = 0; i < tam; i++)
            if(!strcmp(PessoasVelhas[i].Nome, "NULL") == 0)
              printf("%s", PessoasVelhas[i].Nome);
          printf(" é o mais velho de todos.\n");
            
        }
      }
      //Caso o tamanho do vetor de pessoas seja menor igual a 2
      else
      {
        if(Pessoa[0].Idade > Pessoa[1].Idade)
          printf("%s é mais velho que %s.\n", Pessoa[0].Nome, Pessoa[1].Nome);
        else if(Pessoa[1].Idade > Pessoa[0].Idade)
          printf("%s é mais velho que %s.\n", Pessoa[1].Nome, Pessoa[0].Nome);
        else
          printf("%s e %s tem a mesma idade.\n", Pessoa[1].Nome, Pessoa[0].Nome);

      }

      //Reiniciando o valor do Indice:
      indice = 0;

    }//Fim if que verifica se o indice == tam

    setbuf(stdin, NULL);
  }

  printf("Programa encerrado\n");

  return 0;
}
