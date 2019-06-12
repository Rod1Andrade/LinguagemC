#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int bissexto(int ano);
int datasValidas(int dia, int mes, int ano, int bissexto);

int main(void)
{

  char Data[11];

  fgets(Data, 11, stdin);
  Data[strcspn(Data, "\n")] = '\0';

  if(strlen(Data) != 10)
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

  if(datasValidas(vetor[0], vetor[1], vetor[2], bissexto(vetor[2])))
  {
    printf("Datas Validas\n");
  }
  else
  {
    printf("Data inválida\n");
  }

  return 0;
} 

int datasValidas(int dia, int mes, int ano, int bissexto)
{
  if(mes < 1 && mes > 12)
    return 0;

  int conjuntoMeses[] = {1, 3, 5, 7, 8, 10, 12}; 
  int conjuntoMeses2[] = {2, 4, 6, 9, 11};
  
  //Verificação do ano bissexto:
  if(mes == 2 && bissexto == 1)
  {
    if(dia >= 1 && dia <= 29)
      return 1;
  }
  else
  {
    if(dia  < 1 || dia > 28)
      return 0;
  } 

  //Verificação dos meses que vai até 31:
  for(int i = 0; i < 7; i++)
  {
    if(mes == conjuntoMeses[i])
    {
      if(dia >= 1 &&  dia <= 31)  
        return 1;
        break;
    }
  }

  //Verificação dos meses que vai até 30:
  for(int i = 0; i < 5; i++)
  {
    if(mes == conjuntoMeses2[i])
    {
      if(dia >= 1 && dia <= 30)
      {
        return 1;
        break;
      }
    }
  }
  return 0;
}

//Função para cálculo do ano bissexto:
int bissexto(int ano)
{
  if(ano%4 == 0 || ano%400 == 0 && ano%100 != 0)
    return 1;
  return 0;
}
