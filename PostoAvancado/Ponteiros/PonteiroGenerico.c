#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  /**
   * Ponteiros Genéricos é um tipo especial de ponteiro
   * que pode apontar para qualquer tipo.
   *
   * Seu tipo deve ser void (sem retorno);
   *
   * Forma geral: 
   * void *nomePonteiro;
   * */

  //Ponteiro Genérico
  void *ponteiroGenerico; 

  //Ponteiro especifico (tipado): 
  int *ponteiroInteiro, x = 10;

  ponteiroInteiro = &x;
  ponteiroGenerico = &x;

  printf("Endereco de x: %p\n", &x);

  printf("Endereco do ponteiro Generico: %p\n", ponteiroInteiro);

  //void* -> int*
  ponteiroGenerico = &ponteiroInteiro;
  printf("Endereco do ponteiro Generico: %p\n", ponteiroInteiro);

  ponteiroGenerico = ponteiroInteiro;
  printf("Endereco do ponteiro Generico: %p\n", ponteiroInteiro);

  /**
   * Antes de acessar o conteúdo do ponteiro genérico 
   * é necessário fazer um cast para o tipo específico;
   *
   * - Casting: 
   *    *(<tipo especifico>*)ponteiroGenerico;
   *
   * */

  printf("Conteudo do ponteiro genérico: %d\n", *(int*)ponteiroGenerico);

  /**
   * As operações artiméticas com o tipp genérico
   * sao realizadas sempre 1 byte por vez.
   * */

  //Exemplo 
  void *p = 0x5DC;
  printf("p = %d\n", p);
  p++;
  printf("p = %d\n", p);
  p = p + 15;
  printf("p = %d\n", p);
  p = p - 3;
  printf("p = %d\n", p);

  return 0;
}
