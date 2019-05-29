#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  //Contado a quantidade de vogais de uma String: 
  
  char str[30] = "Linguagem de Programacao C"; 
  char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  int ContadorVogais = 0;


  for(int i = 0; i < strlen(str); i++)
  {
    for(int j = 0; j < 10; j++)
    {
      if(str[i] == vogais[j])
      {
        ContadorVogais++;
        break;
      }
    }
  }

  printf("Quantidade de Vogais: %d\n", ContadorVogais);

  return 0;
}
