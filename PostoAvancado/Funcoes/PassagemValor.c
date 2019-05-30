#include <stdio.h>
#include <stdlib.h>
void adciona(int n)
{
   n++;
   printf("Dentro da funcao: n = %d\n", n);
}
int main(void)
{
  
  /**
   *
   *  A Linguagem C permite dois tipos
   *  de passagem de parâmetros para uma função:
   *
   *  "Por valor":
   *  cópia do dado (padrão)
   *
   *  "Por referência":
   *  Endereço do dado original
   *
   * */

  //Exemplo da cópia que acontece:
  int x = 10;
  printf("Antes da chamada da funcao: x = %d\n", x);

  /*
   * Tudo que acontece dentro da função. Quando completado é destruído.
   * Os espaços de memórias são liberados para novas alocações.
   * Por isso a passagem por valor não altera o valor de x fora da função, apenas
   * dentro da função adciona.
  **/

  adciona(x);
  
  printf("Depois da chamada da funcao: x = %d\n", x);

  return 0;
}
