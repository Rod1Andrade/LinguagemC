/**
 * Desenvolva um programa para concatenar duas strings digitadas pelo usuário. As
 * strings devem ser concatenadas em outra variável e convertida para maiúscula.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main(void)
{

  char PalavraA[30], PalavraB[30], PalavraC[60] = "";

  printf("Digite a primeira palavra: ");
  fgets(PalavraA, 30, stdin);

  printf("Digite a segunda palavra: ");
  fgets(PalavraB, 30, stdin);


  //Retirando os caracteres de quebra de linha:
  PalavraA[strlen(PalavraA) - 1] = '\0';
  PalavraB[strlen(PalavraB) - 1] = '\0';

  //Concatenando as Palavras:
  strcat(PalavraC, PalavraA);
  strcat(PalavraC, PalavraB);

  char aux;

  for(int i = 0; PalavraC[i] != '\0'; i++)
  {
    aux = toupper(PalavraC[i]);
    PalavraC[i] = aux;
  }

  printf("Palavra Concatenada: %s\n", PalavraC);

  return 0;
}
