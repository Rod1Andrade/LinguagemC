#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
struct pessoa
{
  char nome[50];  
  int idade;
};

struct aluno
{
  char nome[50];
  char matricula[50];
  int idade;
};
//Com estruturas você traz uma identidade melhor para os 
//seus dados.

int main(int argv, char *argc)
{
  //Inicializando a estrutura
  struct pessoa p;
  struct pessoa p2;
  struct aluno a;
  
  printf("Entre com seu nome: ");
  fgets(p.nome, 50, stdin);
  p.nome[strlen(p.nome)-1] = '\0';
  
  printf("Entre com a sua idade: ");
  scanf("%d", &p.idade);

  //A linguagem C aceita esse tipo de cópia, porque ambas as estruturas são do mesmo tipo (pessoa).
  p2 = p;

  //Caso contrario a cópia devera ser campo a campo: 
  strcpy(a.nome, p.nome);
  a.idade = p.idade;

  printf("\n");

  //Saidas do Pessoa 2:
  printf("Pessoa: \n");
  printf("Nome: %s\n", p2.nome);
  printf("Idade: %d\n", p2.idade);
  
  printf("\n");

  //Saidas do Aluno a;
  printf("Aluno: \n");
  printf("Nome: %s\n", a.nome);
  printf("Idade: %d\n", a.idade);


  return 0;
}
