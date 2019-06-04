#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  /**
   * Função fgets lê strings: 
   *
   * char * fgets(char *str, int tamanho, FILE *file);
   *
   * Retorna:
   * - Em caso de erro NULL
   * - Em caso de sucesso um ponteiro para o primeiro caracter 
   *   de str;
   *
   * */

  int tamanho = 30;
  char str[tamanho];
  FILE *file;
  file = fopen("ArquivoFgets.txt", "r");
  
  if(file == NULL)
  {
    printf("erro na leitura\n");
    getchar();
    exit(1);
  }

  //Ele percorre todo o arquivo, ou seja o tamanho -1 
  //ou para a leitura quando encontra o caractere de nova linha: \n
  char * result = fgets(str, tamanho, file);
  
  if(result == NULL)
    printf("Erro na leitura\n");
  else
    printf("%s", str);

  fclose(file);
  return 0;
}
