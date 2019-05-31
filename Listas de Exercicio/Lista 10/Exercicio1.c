#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argv, char *argc[])
{
  char Vogais[] = {'A', 'E', 'I', 'O', 'U'};
  char Caracter; 
  int ContadorVogal = 0;

  printf("Digite uma vogal ou X para finalizar: ");
  scanf("%c", &Caracter);
  
  Caracter = toupper(Caracter); 

  while(Caracter != 'X')
  {
    for(int i = 0; i < 5; i++)
    {
      if(Caracter == Vogais[i])
      {
        ContadorVogal++;
        break;
      }
    }
    setbuf(stdin, NULL);
    scanf("%c", &Caracter);
    Caracter = toupper(Caracter); 
  }

  if(ContadorVogal != 0)
  {
    printf("\n%d Vogais foram digitadas.\n", ContadorVogal);
  }
  else
  {
    printf("\nNenhuma Vogal foi digitada!\n");
  }
  return 0;
}
