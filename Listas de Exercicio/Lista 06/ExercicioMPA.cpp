#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argv, char *argc[])
{

  //Constantes para Conversão
  const float CONSTANTE_PA = 1e6; // 1 * 10 ^ 6
  const float NEWTON = 9.8;

  //Variaveis referentes aos cálculos
  float T_MPA, PA;
  float Carga, Diametro;

  //Recebe a Tensão de Cisalhamento do úsuario
  printf("Entre com a tensão de cisalhamento admissível(MPA): ");
  scanf("%f", &T_MPA);

  //Conversão de MPA para PA
  PA = T_MPA * CONSTANTE_PA; 

  //Recebe a carga aplicada em toneladasa verticalmente no parafuso
  printf("Entre com a Carga aplicada (toneladas): ");
  scanf("%f", &Carga);

  //Conversão de toneladas Para Newton
  Carga = (Carga * 1000.0) * NEWTON;
   
  //Calculo do Diametro do Parafuso:
  Diametro = sqrt(((Carga / PA) * 4) / 3.141516);

  //1m == 1000mm
  printf("Diametro do parafuso em Milímetro: %.2f\n", Diametro * 1000.0);

  //1Polegada == 25.4mm
  printf("Diametro do parafuso em Polegada: %.2f\n", (Diametro * 1000) / 25.4);

  return 0;
}
