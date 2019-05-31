#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*************************** LÓGICA DE PROGRAMAÇÃO I *****************************
 * Professor: Joilson dos Reis Brito
 * Lista Número: 08
 * Nome do Autor: Rodrigo Moreira Pires de Andrade
 * Data divulgação: 30/04/201*
 * Enunciado: 
 * *******************************************************************************/

//Parametrização de funções: 
void EquacaoGrau2(float a, float b, float c);

int main(int argv, char *argc[]){

  setlocale(LC_ALL, "Portuguese");

  float A, B, C;
  
  printf("Digite o valor de A: ");
  scanf("%f", &A);
  printf("Digite o valor de B: ");
  scanf("%f", &B);
  printf("Digite o valor de C: ");
  scanf("%f", &C);

  EquacaoGrau2(A, B, C);
  return 0;
} 

void EquacaoGrau2(float a, float b, float c){

  //Raizes da equação: 
  float x1, x2;
  if(a > 0)
  {
    //Função Delta() = b^2 - 4ac
    float Delta = pow(b, 2) - 4 * a * c;
    if(Delta > 0)
    {
      //Cálculo das raizes
      x1 = (-(b) + sqrt(Delta)) / (2 * a);
      x2 = (-(b) - sqrt(Delta)) / (2 * a);
      
      //Retorno do cálculo: 
      printf("Duas Raízes são: x1 = %.2f; x2 = %.2f;\n", x1, x2);
    } //Fim do IF
    else{
      printf("Não há raizes reais\n");
    }// Fim do else
  }// Fim do IF
  else
  {
    printf("Não é uma equação do Segundo Grau\n");
  }//Fim do Else

}//Fim da função EquacaoGrau2
