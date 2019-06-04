#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

/**
 * Lê um arquivo contendo um texto em minusculo e 
 * criar outro arquivo com o texto em maisculo.
 * 
 * Depois ler o novo arquivo
 * */

int main(void)
{
  setlocale(LC_ALL, "Portuguese");
  
  FILE *oldFile, *newFile;
  oldFile = fopen("Arquivo.txt", "r");
  newFile = fopen("ArquivoCase.txt", "w");

  if(oldFile == NULL || newFile == NULL)
  {
    printf("Impossivel abrir algum dos arquivos\n");
    exit(1);
  }

  /*
   * Função EOF
   * ler até o fim do arquivo, excelente para lidar 
   * com leitura de binários ou que não seja caracter a 
   * caracter
   * 
   * **/

  int caracterLido = fgetc(oldFile);
  while(!feof(oldFile))
  {
    fputc(toupper(caracterLido), newFile);   
    caracterLido = fgetc(oldFile);
  }
 
  fclose(oldFile);
  fclose(newFile);

  //Agora abre para leitura:
  newFile = fopen("ArquivoCase.txt", "r");
  caracterLido = fgetc(newFile); 
  while(!feof(newFile))
  {
    printf("%c", caracterLido);
    caracterLido = fgetc(newFile); 
  }


  fclose(newFile);

  return 0;
}
