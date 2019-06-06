/**
 * Função FPRINTF, função destinada a armazenar dados
 * formatados em um arquivo: 
 *
 * Forma Geral: fprintf();
 *
 * fprintf(FILE *file, "Tipos de saída", Variáveis);
 * 
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

  setlocale(LC_ALL, "Portuguese");

  char Nome[30] = "Rodrigo Andrade";
  short Idade = 19;
  float Altura = 1.66;

  FILE *Arquivo;
  Arquivo = fopen("FuncaoFprintf.txt", "w");
  if(Arquivo == NULL)
  {
    printf("Impossível abrir o arquivo\n");
    getchar();
    exit(1);
  } 

  //Formatação dos Dados na tela:
  printf("Nome: %s\nIdade: %hd\nAltura: %.2f\n", Nome, Idade, Altura);

  //Formatação dos Dados no arquivo:
  fprintf(Arquivo, "Nome: %s\nIdade: %hd\nAltura: %.2f\n", Nome, Idade, Altura); 

  fclose(Arquivo);
  return 0;
}
