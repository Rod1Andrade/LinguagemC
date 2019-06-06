/***
 * De modo geral, quando se trabalha com arquivo.
 * Acessa-se ele de forma sequencial. Porém a linugagem C
 * permite realizar operaçõs de leitura e escrita randômica usando a 
 * função fseek()
 *
 * FORMA GERAL: 
 *
 * int fseek (FILE *arquivo, long numBytes, int origem);
 *
 * Parâmetros:
 * arquivo -> Ponteiro para o arquivo.
 * numBytes -> É o total de bytes a ser pulado a partir de uma origem.
 * origem -> A partir de onde os numBytes serão contados.
 *
 * return -> ZERO em caso de sucesso.
 *
 * Os valores possíveis para o parâmetro
 * ORIGEM, são definidos por constantes
 * na biblioteca <stdio.h> e são: 
 *
 *  CONSTANTE:      VALOR       SIGNIFICADO 
 *  
 *  SEEK_SET          0         Inicio do arquivo
 *  SEEK_CUR          1         Ponto atual no arquivo
 *  SEEK_END          2         Fim do arquivo
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

  char Nome[30];
  char padd[sizeof(int)];
  int Idade;
} pessoa;


int main(void)
{
  
  FILE *arquivo;
  arquivo = fopen("FuncaoFseek.txt", "w+b");
  if (arquivo == NULL)
  {
    printf("Erro na abertura do arquivo\n");
    getchar();
    exit(1);
  }

  pessoa Pessoa[4];
  
  strcpy(Pessoa[0].Nome, "Rodrigo Andrade");
  Pessoa[0].Idade = 19;
  
  strcpy(Pessoa[1].Nome, "Gabriela Andrade");
  Pessoa[1].Idade = 29;
  
  strcpy(Pessoa[2].Nome, "Bobby Fisher");
  Pessoa[2].Idade = 39;

  strcpy(Pessoa[3].Nome, "Mark U");
  Pessoa[3].Idade = 49;

  int totalGravado = fwrite(Pessoa, sizeof(pessoa), 4, arquivo);

  if(totalGravado != 4)
  {
    printf("Impossível gravar dados.\n");
    getchar();
    exit(1);
  }

  pessoa c;

  //Leitura do segundo registro:
  fseek(arquivo, 2*sizeof(pessoa), SEEK_SET);
  fread(&c, sizeof(pessoa), 1, arquivo);
  printf("Nome: %s\nIdade: %d\n", c.Nome, c.Idade);

  /**
   * REWIND, é simplesmente para retornar a leitura randômica do arquivo, 
   * para o ínicio usando a função rewind()
   *
   * FORMA GERAL: 
   * void rewind(FILE *arquivo);
   *
   * */

  //Retorna o ponteiro para o ínicio do arquivo
  rewind(arquivo);

  //Leitura do último registro:
  fseek(arquivo, 3*sizeof(pessoa), SEEK_SET);
  fread(&c, sizeof(pessoa), 1, arquivo);
  printf("\nNome: %s\nIdade: %d\n", c.Nome, c.Idade);

  fclose(arquivo);
  return 0;
}
