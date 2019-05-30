#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(void)
{
  
  /**
   *
   * Processar entradas (parâmetros), e 
   * gera a saída (return) da função.
   * É formada por declarações de comando.
   *
   * */

  int Numero;

  printf("Digite um numero: ");
  scanf("%d", &Numero);

  printf("Fat: %ld\n", fatorial(Numero));

  return 0;
}

int fatorial(int n)
{
  long Fatorial = 1;
  for(long i = 1L; i <= n; i++)
    Fatorial *= i;

  return Fatorial;
}
