#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  /**
   * Para ler caracteres de um arquivo usamos a função:
   *
   * fgetc()
   *
   * Forma Geral:
   *
   * int fgetc(FILE *file);
   *
   * Retornar:
   * - Em caso de erro: a constante EOF
   * - Em case de sucesso: o caracter
   *
   * */

  FILE *file;
  file = fopen("Arquivo.txt", "r");

  if(file == NULL)
  {
    printf("Impossivel Abrir o arquivo.\n");
    getchar();
    exit(1);
  }

  ///Desse modo lê-se caracter por caracter, até que chege ao fim do arquivo.
  printf("Lendo os dados dentro do Arquivo: \"Arquivo.txt\"\n");
  char caracterLido = fgetc(file);
  while(caracterLido != EOF)
  {
    printf("%c", caracterLido);
    caracterLido = fgetc(file);
  }

  fclose(file);

  return 0;
}
