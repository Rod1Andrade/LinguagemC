#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
  char nome[30];
  char padd [sizeof(int)];
  int idade;
};

int main(void)
{
  FILE *arquivo;
  arquivo = fopen("ArquivoFuncaoFwrite.txt", "rb");
  
  if(arquivo == NULL)
  {
    printf("Erro na leitura do arquivo\n");
    getchar();
    exit(1);
  }

  //Ledo vetor contido no arquivo
  int vetor[5];
  int totalLido = fread(vetor, sizeof(int), 5, arquivo);

  printf("Vetor de inteiros contido dentro do arquivo: \n");
  if(totalLido != 5)
    printf("erro na Leitura do arquivo\n\n");
  else
    for(int i = 0; i < 5; i++)
      printf("%d ", vetor[i]);

  //Lendo Estrutura contida no arquivo:
  struct pessoa p;  

  totalLido = fread(&p, sizeof(struct pessoa), 1, arquivo);

  if(totalLido == 1)
    printf("\n\nLeitura efetuada com sucesso\n\n");

  printf("Estrutura dentro do arquivo: \n");
  printf("Nome: %s\n", p.nome);
  printf("Idade: %d\n", p.idade);

  //Fechando o arquivo:
  fclose(arquivo);

  return 0;
}
