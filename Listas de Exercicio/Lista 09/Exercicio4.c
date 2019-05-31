#include <stdio.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  
  float Notas, Media = 0;
  int contador = 0;

  printf("Digite a nota ou -1 para sair:\n ");
  scanf("%f", &Notas);

  while(Notas != -1)
  {
    if(Nota != -1)
    {
    	contador += 1;
    	Media += Notas;
    	scanf("%f", &Notas);
    }	  
  }
  
  Media /= contador;
  printf("Média: %.2f", Media);

  printf("\n");
  return 0;
}
