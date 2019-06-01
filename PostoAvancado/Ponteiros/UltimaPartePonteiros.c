#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  /**
   * A linguagem C permite criar ponteiros
   * com diferentes niveis de apontamento: 
   * Ponteiros que apontam para outros ponteiros.
   *
   * */

  int x = 10;
  int *px = &x;
  int **pp = &px;

  //endereco em pp: 
  printf("**pp = &%p\n", pp); //&px

  //Conteúdo do endereço: 
  printf("*pp = %d\n", *pp);//&x

  //Conteúdo do endereço do endereço: 
  printf("**pp = %d\n", **pp); //x


  /**
   * É a quantidade de asteriscos (*) na declaração 
   * do ponteiro que indica o número de níveis do ponteiro.
   *
   * */

  //Variavel inteira z
  int z;

  //Ponteiro para int de 1 nível:
  int *p1;

  //Ponteiro para ponteiro de int (2 níveis):
  int **p2;

  //Ponteiro para ponteiro de ponteiro de int (3 níveis);
  int ***p3;

  //Não há limite para declaração de ponteiros.
  //Exemplo:
  char letra = 'A';

  printf("\nEndereco x = %p\n\n", &letra);

  char *ponteiroChar = &letra;
  printf("%c\n", *ponteiroChar);

  char **ponteiroPonteiroChar = &ponteiroChar;
  printf("%c\n", **ponteiroPonteiroChar);

  char ***ponteiroPonteiroPonteiroChar = &ponteiroPonteiroChar;
  printf("%c\n\n", ***ponteiroPonteiroPonteiroChar);

  //Endereços nos quais o ponteirPonteiroPonteiroChar aponta: 
  printf("%p\n",  ponteiroPonteiroPonteiroChar);
  printf("%p\n", *ponteiroPonteiroPonteiroChar);
  printf("%p\n", **ponteiroPonteiroPonteiroChar);
  printf("Dado Bruto: %c\n", ***ponteiroPonteiroPonteiroChar);

  return 0;
}
