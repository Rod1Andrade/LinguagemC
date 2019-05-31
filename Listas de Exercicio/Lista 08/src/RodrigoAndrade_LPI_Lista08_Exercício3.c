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
  
  system("clear");
  unsigned char Opcao;
  float Numero; //Variavel usada no case 2 e case 3
  float A, B, Resultado; //Variaveis usadas no case 1 e case 4

  printf("Menu de opções:\n");
  printf("1. Somar dois números\n");
  printf("2. Raiz quadrada de um número\n");
  printf("3. O cubo de um número\n");
  printf("4. Diferença do maior pelo menor\n");

  printf("Digite a opção desejada: ");
  scanf("%d", &Opcao);

  switch(Opcao)
  {
    case 1:
      system("clear");
      printf("Digite o número A: ");
      scanf("%f", &A);
      printf("Digite o número B: ");
      scanf("%f", &B);
      Resultado = A + B;
      printf("A soma de %.2f + %.2f = %.2f\n", A, B, Resultado);
    break; 

    case 2:
      system("clear");
      printf("Digite um número: ");
      scanf("%f", &Numero);
      printf("A raiz de %.2f = %.2f\n", Numero, sqrt(Numero));
    break; 
    
    case 3:
      system("clear");
      printf("Digite um número: ");
      scanf("%f", &Numero);
      printf("O cubo de %.2f = %.2f\n", Numero, pow(Numero, 3));
    break; 
    
    case 4:
      system("clear");
      printf("Digite o número A: ");
      scanf("%f", &A);
      printf("Digite o número B: ");
      scanf("%f", &B);
      if(A > B)
      {
        printf("%.2f - %.2f = %.2f\n", A, B, (A - B));
      }//Fim do if
      else if(B > A)
      {
        printf("%.2f - %.2f = %.2f\n", B, A, (B - A));
      }//Fim do else-IF
      else
      {
        printf("Números Iguais\n");
      } 
    break; 
    
    default:
       printf("Erro! Opção Inválida\n");
    break;
  }

  getchar(); //Espera a entrada do úsuario
  return 0;
}

