#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
{
  char nome[50];
  short idade;
};


int main(int argv, char *argc[])
{
  
  //Vetor de uma Estrutura
  struct pessoa p[5];

  for(int i = 0; i < 3; i++)
  {
    printf("Nome: ");
    fgets(p[i].nome, 50, stdin);
    p[i].nome[strcspn(p[i].nome, "\n")] = '\0';
    
    printf("Idade: ");
    scanf("%hd", &p[i].idade);
    
    printf("\n");
    setbuf(stdin, NULL);
  }

  return 0;
}
