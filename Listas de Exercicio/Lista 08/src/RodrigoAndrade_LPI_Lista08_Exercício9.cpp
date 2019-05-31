#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void){
  setlocale(LC_ALL, "Portuguese");

  float Peso, Altura, IMC;

  printf("===========================\n");
  printf("\tIndice de Massa Corporal\n");
  printf("===========================\n");

  printf("Atura: ");  
  scanf("%f", &Altura);
  printf("Peso: ");  
  scanf("%f", &Peso);

  //IMC = Peso / Altura^2
  IMC = Peso / (pow(Altura, 2));

  printf("%.2f\n", IMC);

  if(IMC < 17.0)
  {
    printf("Muito Abaixo do Peso.\n");
  }
  else if(IMC >= 17.0 && IMC <= 18.49)
  {
    printf("Abaixo do Peso.\n");
  }
  else if(IMC >= 18.5 && IMC <= 24.99)
  {
    printf("Peso Ideal.\n");
  }
  else if(IMC >= 25.0 && IMC <= 29.99)
  {
    printf("Acima do Peso.\n");
  }
  else if(IMC >= 30.0 && IMC <= 34.99)
  {
    printf("Obesidade I.\n");
  }
  else if(IMC >= 35.0 && IMC <= 39.99)
  {
    printf("Obseidade II.\n");
  }
  else
  {
    printf("Obesidade III.\n");
  }


  return 0;
}
