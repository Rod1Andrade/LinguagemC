
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
struct pessoa
{
  char Nome[40];
  char pad[5];
  int Idade;

};

int main(int argv, char *argc[])
{

  /* 
   * 1 Plano: 
   *   - Criar um vetor de Pessoas e um vetor de PessoasMaisVelhas: 
   *   O vetor Pessoas pode ser um vetor de tamanho estático?
   *   O vetor PessoasMaisVelhas pode ser um vetor de tamanho estático?
   *
   *   Ambas as resposta: Não.
   *   
   *   Quero partir de um tamanho minímo, que será 2. E realocar memória, até que seja digitado fim.
   *
   * **/

  int tamanhoMinimo = 2, index = 0;
  struct pessoa *p;
  struct pessoa *pVelha = NULL;

  long tamanho = sizeof(p);
  printf("tamanho %zu\n", tamanho);
  p = (struct pessoa *) malloc(tamanhoMinimo * tamanho);

  while(1)
  {
     setbuf(stdin, NULL);

    //Critério para realocação de memória: 
    if(index >= tamanhoMinimo)
    {
      p = (struct pessoa *) realloc(p, (tamanhoMinimo*2) * tamanho);
      tamanhoMinimo = index*2;
      printf("Tamanho Mininmo: %d\n", tamanhoMinimo);
    }

    printf("#%d - Dados: \n", index);
    printf("Nome: ");
    fgets(p[index].Nome, 40, stdin);
    p[index].Nome[strlen(p[index].Nome) - 1] = '\0';

    //Critério de parada
    if(strcasecmp(p[index].Nome, "fim") == 0)
      break;

    printf("Idade: ");
    scanf("%d", &p[index].Idade);

    setbuf(stdin, NULL);

    index++;
  }

  printf("\n");
  //Imprimindo todos os dados do vetor: 
  for(int i = 0; i < index; i++)
  { 
    printf("[%d] --> Nome: %s, Idade: %hd\n", i, p[i].Nome, p[i].Idade);  
  }

  //Percorrendo o vetor p e verificando quem te a idade maior:
  int IdadeMaior = p[0].Idade;
  for(int i = 1; i < index; i++)
  {
    if(p[i].Idade > IdadeMaior)
    {
      IdadeMaior = p[i].Idade;
    }
  }

  printf("\nMaior Idade da Lista: %d\n", IdadeMaior);

  //Adcionando Idades iguais a maiores, dentro da lista:
  int Quantidade = 0;
  for(int i = 0; i < index; i++)
  {
    if(p[i].Idade == IdadeMaior)
    {
      pVelha = (struct pessoa *) realloc(pVelha, (i+3) * tamanho);
      strcpy(pVelha[Quantidade].Nome, p[i].Nome);
      pVelha[Quantidade].Idade = p[i].Idade;
      Quantidade++;
    }
  }


  for(int i = 0; i < Quantidade; i++)
  {
    printf("%s", pVelha[i].Nome);
    if(i != Quantidade-1)
      printf(", ");
  }
  if(Quantidade != 1)
    printf(" tem a mesma idade.\n");
  else
    printf(" é o mais velho.\n");

  free(p);
  free(pVelha);

  return 0;
}
