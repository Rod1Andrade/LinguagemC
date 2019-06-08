#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  //Numeros Divisiveis por 10;
  const int Numero = 359;
  int Menor = Numero;
  printf("Numeros Divisiveis: ");
  for(int i = 2; i <= Numero; i++)
  {
    if((Numero % i) == 0)
    {
      if(i <= Menor)
        Menor = i;
      printf("%d ", i);
    }
  }

  printf("\nMenor Número Divisivel por %d é: %d\n", Numero, Menor);

  /*
   * ACHAR O NUMERO DIVISIVEL POR CADA UM DOS NUMEROS DE 1 A 10:
   * **/
  int N, nro;
  N = nro = 10;

  int achou = 0;
  while(achou == 0)
  {
    achou = 1;
    for(int i = 2; i <= N; i++)
    {
      if(nro % i != 0)
      {
        achou = 0; 
        break;
      }
    }
    if(achou == 1)
      printf("NRO = %d\n", nro);
    else
      nro = nro + 2;
  }
  return 0;
}
