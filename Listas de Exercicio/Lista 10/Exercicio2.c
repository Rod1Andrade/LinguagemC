#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  float Nota, Media = 0;
  int Count = 0; 

  while(Count < 10)
  {
    
    setbuf(stdin, NULL);

    printf("Digite a nota do aluno %d: ", Count + 1); 
    scanf("%f", &Nota); 
        
    while(Nota < 0.0 || Nota > 10)
    {
      printf("\nDigite a nota novamente: ");
      scanf("%f", &Nota); 
      printf("\n");
    }

    Media += Nota;
    Count++;

  }

  printf("Média das notas %.2f\n", Media / Count);

  return 0;
}
