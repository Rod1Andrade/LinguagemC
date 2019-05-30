#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * O comando typedef permite que o programador (eu)
 * de nickname para um tipo já existente.
 *
 * Forma Geral: 
 * typedef tipo_existente nickname;
 * */

typedef struct
{
  char nome[50];
} pessoa;

int main(int argv, char *argc[])
{


  pessoa p;
  fgets(p.nome, 50, stdin);
  p.nome[strlen(p.nome) - 1] = '\0';

  puts(p.nome);
  return 0;
}
