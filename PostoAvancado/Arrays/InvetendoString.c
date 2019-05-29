#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  //Caracter auxiliar:
  char aux;

  //Palavra a ser invertida
  char str[30]; 

  //Destino da palavra invertida
  char dest[30];

  setbuf(stdin, NULL);

  //Entrada do úsuario
  printf("Enter with the word: "); 
  gets(str);

  //Copiando string origem para string destino de forma invertida (não optimizado)
  int tam = strlen(str);
  for(int i = tam-1, j = 0; i >= 0; i--)
    dest[j++] = str[i];

  //Imprimindo string invertida
  puts(dest);

  //Reiniciando o valor da variavel tamanho: 
  tam = strlen(dest);

  //Desenvetendo de forma optimizada:
  for(int i = 0; i < tam / 2; i++)
  {
    aux = dest[i]; 
    dest[i] = dest[tam-1-i];
    dest[tam-1-i] = aux;
  }
  
  //Imprimindo string desinvertida
  puts(dest);

  return 0;
}
