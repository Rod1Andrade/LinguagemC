#include <stdio.h>
#include <stdlib.h>

//Parametrização de funções:
int quadrado(int a);

int main(int argv, char *argc[])
{
  
  /**
   * Função: Conjunto de comandos que recebe nome 
   * e pode ser chamado em parte do programa, quantas vezes
   * forem necessárias.
   *
   * Vantagens: Estruturação do programa
   * e reutilização de códigos.
   *
   * Forma Geral: 
   * tipo nome_funcao(parametros)
   * {
   *    conjunto de declarações e 
   *    comandos.
   * }
   *
   * */

  printf("%d\n", quadrado(5));

  return 0;
}

/**************************************************************************/

int quadrado (int a)
{
  return a * a;
}
