#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *file;
  file = fopen("Arquivo.txt", "w");

  
  /**
   * Função: FPUTC();
   * Escreve um caractere em um arquivo:
   *
   * E retorna:
   *    - Em caso de erro: A constante EOF;
   *    - Em caso de sucesso: o próprio Caractere;
   *
   * FORMA GERAL: 
   *  int fputc(char caracter, FILE *file);
   * */

  if(file == NULL)
  {
    printf("Erro na Abertura\n");
    exit(1);
  }

  //Armazenando os caracteres de A a Z dentro do arquivo
  char caracter = 65; 

  for(int i = 0; i < 26; i++)
  {
    fputc(caracter++, file);
  }

  fputc('\n', file);

  //Aramazenando uma String caracter a caracter:
  char texto[50] = "Rodrigo Andrade, estudante da linguagem C";

  puts(texto);

  for(int i = 0; i < strlen(texto); i++)
  {
    fputc(texto[i], file);
  }
  fclose(file);
  return 0;
}
