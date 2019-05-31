#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  char Sexo; 
  short Idade;



  while(1)
  {
    setbuf(stdin, NULL);

    printf("Digite a idade ou uma idade negativa para finalizar: ");
    scanf("%d", &Idade);
    
    if(Idade < 0)
      break;

    setbuf(stdin, NULL);

    printf("Digite o sexo [F - Fem M - Masc]: ");
    scanf("%c", &Sexo); 
    
    Sexo = toupper(Sexo);

    if(Idade >= 18 && Sexo == 'M')
    {
      printf("Você deve se apresentar para o exécito esse ano!\n");
    }

  }

  return 0;
}
