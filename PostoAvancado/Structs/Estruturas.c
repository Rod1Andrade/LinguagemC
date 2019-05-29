#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Structs:
struct pessoa
{
  char nome[50];
  int idade;
};

int main(int argv, char *argc[])
{
  
  setlocale(LC_ALL, NULL);

  /*
   * A linguagem C nos permite criar 
   * nossos próprios tipos de variaveis.
   * Um deles é o struct, também chamada
   * de ESTRUTURA.
   * **/

  //Declaração de uma variável struct
  struct pessoa p;

  //Acessando campos da Estrutura:
  printf("Digite seu nome: ");
  fgets(p.nome, sizeof(p.nome), stdin);

  int index = strcspn(p.nome, "\n");
  p.nome[index] = '\0';

  printf("Digite sua idade: ");
  scanf("%d", &p.idade);

  printf("Seja bem vindo senhor %s.Você tem %d anos.\n", p.nome, p.idade);

  return 0;
}
