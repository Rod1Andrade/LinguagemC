#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  /**
   * A função FOPEN(): Permite abrir um
   * arquivo em um determinado modo de leitura: 
   *
   * FORMA GERAL: 
   * FILE * fopen(char *nome, char *modo);
   * 
   * nome = caminho do arquivo, você pode passar o caminho de duas formas: 
   * - Absoluta: O caminho desde a origem do sistema;
   * - Relativa: relativa a pasta do código fonte que está tratando o arquivo.
   *
   * */

  //Exemplo:
  FILE *file;
  file = fopen("Arquivo.txt", "w");

  if(file == NULL)
  {
    printf("Erro na Abertura!\n");
    getchar();
    exit(1);
  }

  //Finalizada as operações com os arquivos, feche o arquivo:
  fclose(file);

  return 0;
}
