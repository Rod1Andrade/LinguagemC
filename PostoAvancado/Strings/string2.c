#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 
  //Copiar o valor de uma string para outra sem as funções:
  char str1[20] = "Hello World"; 
  char str2[20];

  //str2 = str1 (errado!)
  
  //Método 1:
  int i;
  for(i = 0; str1[i] != '\0'; i++)
    str2[i] = str1[i];
  str2[i] = '\0';

  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);

  return 0;
}
