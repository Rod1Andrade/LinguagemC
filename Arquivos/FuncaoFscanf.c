/**
 * Função FSCANF: Permite ler dados formatados de um arquivo.
 *
 * FORMA GERAL: 
 *
 * fscanf(FILE *arquivo, "Tipos de entrada", Variáveis);
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{  
  setlocale(LC_ALL, "Portuguese");

  FILE *arquivo;
  arquivo = fopen("FuncaoFprintf.txt", "r");

  if(arquivo == NULL)
  {
    printf("Impossível ler o arquivo.\n");
    getchar();
    exit(1);
  }

  //Quando se lê dados formatados, deve se considerar todas as informações
  //que estão dentro do arquivo de texto.
  char Texto[30], Nome[30];
  short Idade;
  float Altura;

  fscanf(arquivo, "%s %s", Texto, Nome);
  printf("%s %s\n", Texto, Nome);
  fscanf(arquivo, "%s %hd", Texto, &Idade);
  printf("%s %hd\n", Texto, Idade);
  fscanf(arquivo, "%s %f", Texto, &Altura);
  printf("%s %.2f\n", Texto, Altura);

  return 0;
}
