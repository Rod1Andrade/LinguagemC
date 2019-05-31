#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <math.h>

int main(int argv, char *argc[]){
  
  int LadoA, LadoB, LadoC;

  printf("Digite os lados do triangulo: "); 
  scanf("%d %d %d", &LadoA, &LadoB, &LadoC); 

  if(abs(LadoB - LadoC) < LadoA && LadoA < LadoB + LadoC){
    //Triângulo escaleno: Todos os lados são diferentes
    if(LadoA != LadoB && LadoA != LadoC && LadoC != LadoB){
      printf("Triângulo Escaleno");
    }else if(LadoA == LadoB && LadoA == LadoC && LadoC == LadoB){
      //Triângulos Equilátero: Todos os lados iguais
      printf("Triângulo Equilátero"); 
    }else{
      printf("Triângulo Isóceles");
    }
  }else{
    printf("Não é um triangulo."); 
  } 

  printf("\n");
  return 0;
}
