#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
{
  char nome[30];
  char padd[sizeof(int)];//Padding para inteiro
  int idade;
};

int main(void)
{
  
  /**
   *  A função de escrita de blocos de byte  permite escrever dados mais complexos,
   *  como os tipo int, float, double, array, ou  mesmo tipos definidos pelo programador,
   *  como por exempli: Unions e Structs.
   *
   *  Prefêrencia de uso: Arquivos Binários (faz mais sentindo copiar como o dado está disposto na memória).
   *
   *  Para escever um bloco de bytes, use a função fwrite()
   *
   *  Forma Geral: 
   *  int fwrite(void *buffer, int bytes, int count, FILE *file);
   *
   *
   * */

  FILE *arquivo;

  //Abrindo no modo escrita binária, caso não exista o arquivo, ele é criado.
  arquivo = fopen("ArquivoFuncaoFwrite.txt", "wb");

  if(arquivo == NULL)
  {
    printf("Impossivel encontrar o arquivo\n");
    getchar();
    exit(1);
  }

  //Armazenar um veto de inteiros dentro do arquivo
  //VETOR(dado complexo)
  int vetor[5] = { 1, 2, 3, 4, 5 }; 
  int totalGravado = fwrite(vetor, sizeof(int), 5, arquivo);

  //Se o total gravado for diferente do tamanho do vetor, que dizer que comprometeu algum dado:
  if(totalGravado != 5)
  {
    printf("Erro ao gravar dados\n");
    getchar();
    exit(1);
  }
  else
  {
    printf("Dados salvos com sucesso\n");
  }

  //Armazena uma estrutura dentro de um arquivo binário.
  struct pessoa p;
  strcpy(p.nome,  "Rodrigo Andrade");
  p.idade = 19;

  totalGravado = fwrite(&p, sizeof(struct pessoa), 1, arquivo);
  if(totalGravado == 1)
    printf("Estrutura salva com sucesso\n");

  fclose(arquivo);

  return 0;
}
