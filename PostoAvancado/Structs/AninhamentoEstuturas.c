#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Área de estruturas
struct endereco
{
  char rua[50];
  int numero;
};

struct pessoa
{
  char nome[50];
  int idade;

  //Relacionamento tem-um
  struct endereco ender;
};

int main(int argc, char *argc)
{
  
  //Declaração
  struct pessoa p;

  strcpy(p.nome, "Rodrigo Andrade"); 
  p.idade = 19;

  strcpy(p.ender.rua, "Rua dos Bobos");
  p.ender.numero = 0;  

  return 0;
}
