#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*************************** LÓGICA DE PROGRAMAÇÃO I *****************************
 * Professor: Joilson dos Reis Brito
 * Lista Número: 08
 * Nome do Autor: Rodrigo Moreira Pires de Andrade
 * Data divulgação: 30/04/2019
 * Enunciado: 
 * *******************************************************************************/

//Parametrização de funções: 

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, "Portuguese");
  
  float x; 

  printf("Digite o valor de x: ");
  scanf("%f", &x);

  if(x < 1)
  {
    printf("f(x) = %.2f\n", (4 - pow(x, 2)) );
  }//Fim do if
  else if(x > 1)
  {
    printf("f(x) = %.2f\n", 2 + pow(x,2));
  }//Fim do else-if
  else
  {
    printf("f(x) = %.2f\n", 2.00);
  }//Fim do else

  getchar();
  return 0;
}
