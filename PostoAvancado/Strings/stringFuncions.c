#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char *argc[])
{

  /*
   *  strlen    -> Tamanho da String
   *
   *  strcpy    -> Copiar uma String
   *  
   *  strcat    -> Concatenar duas Strings
   *
   *  strcmp    -> Comparar duas Strings
   *
   * **/

  //Funções básicas da biblioteca <string.h>
  int size;
  char origem[30] = "Hello World in C"; 
  char destino[30];
  
  //char *strcpy(char *dest, const char *src);
  strcpy(destino, origem);

  //char *strcat(char *dest, const char *src); 
  //concatena no fim da string
  strcat(destino, " is Good");

  //tamanho de caracteres até o \0
  size = strlen(destino);
  printf("Tamanho: %d caracteres\n", size);

  //Saída na tela: 
  puts(destino);

  //Verificando sem as Strings são iguais
  //char *strcmp(cosnt char *s1, const char *s2) : 0 -> equals ? 1 - differents;
  if(strcmp(origem, destino) == 0)
    printf("Equals\n");
  else
    printf("Different.\n");


  return 0;
}
