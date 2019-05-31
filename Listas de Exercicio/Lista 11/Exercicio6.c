#include <stdio.h>

int main(void)
{

  /** 
    1\n 
    1 2\n
    1 2 3\n
    1 2 3 4\n
    1 2 3 4 5\n
    ...
    1 2 3 4 5 6 7 8 9 10\n

    Utilizei uma variavel auxiliar que sempre vai receber o valor de 1
    E comparo ela com uma valor máximo que em um primeiro momento é 2
    e depois de imprimir os valores até que sejam menor do que Max.
    Então Incrementasse o valor de Max e Incrementa-se o valor de Count
    No Looping externo acontece 10 vezes, acontece a mesma repetição exponêncialmente
    dentro do while mais interno
  * **/

  int Count = 1, Max = 2, Aux;
  do
  { 
    Aux = 1;
    while(Aux < Max)
    {
      printf("%d ", Aux); 
      Aux++;
    }
    printf("\n");
    Max++;
    Count++;
  }while(Count <= 10);

  printf("\n");

  return 0;
}
