#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

  char Data[11];

  fgets(Data, 11, stdin);
  Data[strcspn(Data, "\n")] = '\0';

  if(strlen(Data) != 1)
  {
    printf("Data Inválida\n");
    printf("tamanho: %ld\n", strlen(Data));
  }
  for(int i = 0; Data[i] != '\0'; i++)
  {
    if(Data[i] != '/' && !isdigit(Data[i]))
    {
      printf(" %c ", Data[i]);
      printf("\n Não é um digito válido para datas");
    }

  }

  int vetor[3];
  char *token;

  token = strtok(Data, "/");
  vetor[0] = atoi(token);

  for(int i = 1; i < 3; i++)
  {
    token = strtok('\0', "/"); 
    vetor[i] = atoi(token);
  }

  printf("vetor[0] = %d\n", vetor[0]);
  printf("vetor[1] = %d\n", vetor[1]);
  printf("vetor[2] = %d\n", vetor[2]);

  return 0;
} 

