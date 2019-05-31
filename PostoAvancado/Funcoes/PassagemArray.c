#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int n)
{
  for(int i = 0; i < n; i++)
    printf("%d\n", *(v+i));  
}

int main(void)
{
  
  /*
   * Arrays são sempre passados "por referência" 
   * para um função.
   *
   * Isso evita cópias desnecessárias de grandes 
   * quantidades de dados para outras área da memória
   * durante a chamada da função, o que afetaria o desempenho
   * do programa. (atenção)
   *
   * (tipo *m, int n);
   * (tipo m[], int n);
   * (tipo m[5], int n);
   *
   * **/

  int vetor[] = {-10, 10, 20, 30, 40 };

  //Observação, não necessita do operador de endereço:
  //O nome do vertor é o endereço da sua posição inicial na memória.
  imprime(vetor, 5);

  return 0;
}
