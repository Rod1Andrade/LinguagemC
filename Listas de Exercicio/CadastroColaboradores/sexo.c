#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
  char sexo, temp;
  scanf("%c", &temp);

  sexo = temp;
  printf("sexo: %c\n", sexo);
  setbuf(stdin, NULL);
  while(sexo != 'M' && sexo != 'F')
  {
    printf("sexo: %c\n", sexo);
    setbuf(stdin, NULL);
    scanf("%c", &temp);
    sexo = temp;
  
  if(sexo != 'M' && sexo != 'F')
  {
    printf("Invalido\n");
  }
  else
  {
    printf("Valido\n");
  }

  return 0;
}
