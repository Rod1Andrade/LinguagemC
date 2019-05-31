#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/**
 * @author: Rodrigo Andrade
 * Lidando com arquivos em C (obs: É muito mais simples em C++ e em JAVA)
 *
 * */

//Estrutura de um produto: 
typedef struct Product PRODUCT;
struct Product{
  int ID;
  char nameProduct[300];
  float priceProduct;
};


//Parametrização de funções
void header(); 
void inputData();
void listData();
void remover();
void buyProduct();

int main(void) {

  //Definindo local 
  setlocale(LC_ALL, "Portuguese");

  /**
   * Abrir um arquivo de texto contendo os dados dos produtos.
   * Arquivos: Coleção de bytes armazenados em um dispositivo secundário.
   * FILE* nomePonteiroArquivos; (Fluxo dos arquivos, leitura e escrita).
   * TIPO: 
   *    - BINÁRIOS
   *
   * Para acessar:
   *  - Nome relativo (relativa a pasta do codigo fonte)
   *  - Nome absoluto (endereço completo do arquivo)
   *
   *  MODOS DE ABERTURA:
   *  "r"   --> Leitura de Arquivo texto
   *  "w"   --> Escrita de arquivo Texto
   *  "rb"  --> Leitura de arquivo Binário
   *  "wb"  --> Escrita de arquivo Binário
   *  "a"   --> Escrita. Os dados serão armazenados no fim do arquivo (append). 
   *
   *  LEITURA:
   *  int fgetc(FILE *fp);
   *
   * */


  unsigned char option; 

  do{

    //Limpa o buffer do teclado
    setbuf(stdin, NULL);

    //Chamada do header para estilização
    header(); 

    //Menu de escolha
    printf("1 - Inserir Produto\n"); 
    printf("2 - Listar  Produto\n"); 
    printf("3 - Remover Produto\n"); 
    printf("4 - Comprar Produto\n"); 
    printf("0 - Sair\n"); 

    printf("Digite a opção: "); 
    scanf("%d", &option); 

    //Menu de opções
    switch(option){
      case 1:
        inputData();
        break;
      case 2:
        listData();
        getchar();
        break;
      case 3:
        listData();
        int id;
        printf("Digite o ID a ser removido (-1 Cancela): ");
        scanf("%d", &id); 
        remover(id);
        break;
      case 4:
        buyProduct();
        break;
      case 0:
        printf("Até mais :D \n");
        break;
      default:
        printf("Opção invalida\n");
        break;  
    }


  }while(option != 0); 

  //Fim do prorama
  printf("\n");
  return 0; //EXIT_ON_SUCCESS
}

/* Funções do programa  */
void header(){
  system("clear");
  printf("-------------------------------------\n"); 
  printf("INSERIR, LISTAR E COMPRAR PRODUTOS\n");
  printf("-------------------------------------\n"); 
}
/**
 * @author: Lucas Lima (stackOverFlow: https://pt.stackoverflow.com/questions/46461/como-verificar-em-c-se-o-ficheiro-est%C3%A1-vazio)
 * @return: Tamanho do arquivo
 * */
int get_size(const char* file_name){
  FILE *file = fopen(file_name, "r");

  if(file == NULL)
    return 0;

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fclose(file);

  return size;
}

/**
 * @author: Rodrigo Andrade
 * Persistir dados em um arquivo de texto
 * */
void inputData(){

  int continuar = 1;


  //Referência a estrutura de Produtos
  PRODUCT prd;

  //FILE --> Ponteiro para o tipo FILE
  FILE *arquivo;

  //APPENDICE BINARY (insere os dados binários ao fim do arquivo)
  arquivo = fopen("Produtos.txt", "ab");

  if(arquivo == NULL){
    fprintf(stderr, "Arquivo não encontrado");
  }else{

    //Cria abertura temporaria de Produtos para verificar o último ID
    FILE *cmp;
    cmp = fopen("Produtos.txt", "rb");
    int idCount;
    if(get_size("Produtos.txt") == 0){
      idCount = 0;
    }else{
      while(fread(&prd, sizeof(PRODUCT), 1, cmp)){
        idCount = prd.ID;
      } //fim do while
      idCount += 1;
    }
    do{

      //Chamada do Headeer para estilização
      header();

      //Adciona dados na estrutura de PRODUTCTS prd refenciada dentro da função
      setbuf(stdin, NULL);

      //Adciona o ultimo ID + 1 
      prd.ID = idCount;

      setbuf(stdin, NULL);
      printf("Entre com o Nome do Produto: "); 
      gets(prd.nameProduct);

      setbuf(stdin, NULL);
      printf("Entre com o Preço do Produto: ");
      scanf("%f", &prd.priceProduct); 

      //Escreve em uma linha do arquivo a referência para PRODUCT prd (ref, tamanho, n linhas, destino);
      fwrite(&prd, sizeof(PRODUCT), 1, arquivo);

      setbuf(stdin, NULL);
      //Ponto chave da execução: (continue or break)
      printf("Deseja adcionar mais Produtos? [1/0): "); 
      scanf("%d", &continuar);

      setbuf(stdin, NULL);

      //Contador do ID
      idCount++;

    }while(continuar);

    //Depois de armazenar dados no arquivo... Ocorre o fechamento do mesmo
    fclose(arquivo);

  }

} //Fim da função InputData()

/**
 * @author: Rodrigo Andrade
 * Listar dados contidos no arquivo.
 * */
void listData(){

  //Header para estilização
  header();

  //Instancia da estrutura PRODUCT
  PRODUCT prd;

  //Abre o arquivo para leitura
  FILE *arquivo;
  arquivo = fopen("Produtos.txt", "rb");

  if(arquivo == NULL)
    fprintf(stderr, "Erro na abertura do arquivo\n");
  else{
    printf("ID\n"); 
    while(fread(&prd, sizeof(PRODUCT), 1, arquivo )){
      printf("%d - %s - R$ %.2f\n", prd.ID,  prd.nameProduct, prd.priceProduct);
    } //Fim do while

  } //Fim do else

  //Fechamento do arquivo
  fclose(arquivo);

  setbuf(stdin, NULL);
}// Fim do ListData()

/**
 * @author: Rodrigo Andrade
 * @param: identificador que vai ser relacionar com o dado da estrutura
 *
 * Remove produto da arquivo de texto, para isso cria-se um arquivo temporario
 * copia-se os dados exceto o dado a ser removido.
 * apaga o arquivo antigo, renomeia o arquivo atual.
 *
 * Finaliza o processo de exclusão
 *
 * */
void remover(int identificador){

  //Identificador para ser comparado 
  int id = identificador;

  //Estrutura de dados
  PRODUCT prd;

  //Arquivo Original
  FILE *arquivo;

  //Abre o arquivo, tanto para leitura quanto para escrita
  arquivo = fopen("Produtos.txt", "a+b"); 

  //Arquivo temporario que vai receber os dados novos: 
  FILE *temp;

  if(arquivo == NULL)
    fprintf(stderr, "Arquivo não encontrado");
  else{

    temp = fopen("temp.txt", "wb");

    //Copia todos os dados exceto o a ser excluido para um arquivo temporario
    while(fread(&prd, sizeof(PRODUCT), 1, arquivo)){
      if(id != prd.ID){
        fwrite(&prd, sizeof(PRODUCT), 1, temp);
      }
    }
  }

  fclose(arquivo);
  fclose(temp);

  remove("Produtos.txt");
  rename("temp.txt", "Produtos.txt");

} 


/**
 * @author: Rodrigo Andrade
 * Compra o produto, se a compra for efetuada, o produto é removido
 *
 * */
void buyProduct(){

  int id;
  float balance;

  //Chama a função para listar
  listData();

  //Abre o arquivo
  PRODUCT prd;
  FILE *arquivo;

  arquivo = fopen("Produtos.txt", "rb"); 

  if(arquivo == NULL)
    fprintf(stderr, "Arquivo não encontrado"); 
  else{

    printf("Entre com a quantidade de dinheiro: "); 
    scanf("%f", &balance);

    printf("Digite o ID do produto a ser comprado: "); 
    scanf("%d", &id);

    setbuf(stdin, NULL);

    //Verifica onde os dados são correspondentes
    while(fread(&prd, sizeof(PRODUCT), 1, arquivo)){
      if(id == prd.ID){
        if(prd.priceProduct <= balance){
          printf("Produto Comprado\n"); 
          remover(id);
          break;
        }else{
          printf("Dinheiro insuficiente\n");
        }
      }
    }
  }
  getchar();
} //Fim do BuyProduct();