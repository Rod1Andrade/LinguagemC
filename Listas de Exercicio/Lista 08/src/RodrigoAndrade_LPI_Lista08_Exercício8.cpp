#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
  setlocale(LC_ALL, "Portuguese");

  unsigned short Idade;

  printf("Digite sua idade: ");
  scanf("%hu", &Idade);

  //Idade = 0b1111111111111111; --> Para saber o tamanho máximo que cabe em um unsigned short
  printf("Idade digitada: %hu\n", Idade);

  if(Idade > 0 && Idade < 15)
  {
    printf("Criança\n");
  }
  else if(Idade >= 15 && Idade < 30)
  {
    printf("Jovem\n");
  }
  else if(Idade >= 30 && Idade < 60)
  {
    printf("Adulto\n");
  }
  else
  {
    printf("Idoso\n");
  }

  return 0;
}
