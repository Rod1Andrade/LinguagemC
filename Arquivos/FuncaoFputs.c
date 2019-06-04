/**
 * Função para armazenar String
 *
 * int fputs(char *str, FILE *file);
 *
 * retorna: 
 * A constante EOF em caso de erro
 * Qualquer valor diferente de 0 em caso de sucesso
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

  FILE *file;
  file = fopen("ArquivoFputs.txt", "w");

  if(file == NULL)
  {
    printf("Erro na abertura do arquivo\n");
    getchar();
    exit(1);
  }

  //String a ser gravada: 
  char texto[40] = "Linguagem C";

  //Gravando e colocando retorno em uma variavel inteira:
  int retorno = fputs(texto, file);

  if(retorno == EOF)
    printf("Erro na gravacao\n");

  fclose(file);
  return 0;
}
