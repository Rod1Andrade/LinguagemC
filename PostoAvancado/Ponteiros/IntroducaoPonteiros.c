#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
  
  //Ponteiros:
  char *ponteiroChar;

  //Variáveis: 
  char letra = 'A'; 
  char x;

  //Ponteiro para char recebe o enderço de memória da váriavel letra
  ponteiroChar = &letra;

  //Imprime o conteúdo do ponteiro, que é o valor contido no endereço de letra
  printf("%c\n", *ponteiroChar);

  //Atribui o conteudo do ponteiro de char para x
  x = *ponteiroChar;

  return 0;
}
