#include <stdio.h>
#include <stdlib.h>

///Replicando a função strlen da biblioteca string.h
int Strlen(char *s)
{
  char *ptr_inicial = s;
  while(*s != '\0')
  {
    s++;
  }

  return (int)(s - ptr_inicial);
}

int main(void)
{
  char s[100] = "Rodrigo";
  printf("Tamanho = %d\n", Strlen(s));
  return 0;
}
