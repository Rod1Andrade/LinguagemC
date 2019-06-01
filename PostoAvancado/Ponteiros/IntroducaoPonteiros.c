#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
  /**
   * Ponteiro: Tipo especial de variável que armazenam endereços
   * na memória.
   *
   * */
  
  //Ponteiros:
  char *ponteiroChar;//Ponteiros não inicializados apotam para um lugar indefinido;
  ponteiroChar = NULL; //Ponteiro pode ter um valor especial NULL, que é o endereço de lugar nenhum;

  //Variáveis: 
  char letra = 'A'; 
  char x;

  //Ponteiro para char recebe o enderço de memória da váriavel letra;
  ponteiroChar = &letra;

  //Imprime o conteúdo do ponteiro, que é o valor contido no endereço de letra;
  printf("%c\n", *ponteiroChar);

  //Atribui o conteudo do ponteiro de char para x;
  x = *ponteiroChar;

  //Ponteiros apotam para endereços na memória:
  char *pc, c = 'B';

  //Ponteiro para char recebe o endereço na memória da variável c
  pc = &c;

  printf("Address: \n"); 
  printf(" c = %p\n", &c);
  printf("pc = %p\n", pc);

  /*
   * O operador (*) asterisco permite
   * modificar o conteúdo da posição 
   * de memória apontada.
   * Em outras palavras, o operador asterisco acessa
   * o valor na qual o ponteiro aponta.
   * **/

  //Modificando o valor de c indiretamente.
  *pc = 'Z';

  printf("\nContents: \n");
  printf("  c = %c\n", c);
  printf("*pc = %c\n", *pc);


  return 0;
}
