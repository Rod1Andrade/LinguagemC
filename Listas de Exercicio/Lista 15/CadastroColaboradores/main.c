/**
* @author: Rodrigo Andrade
* Data: 13/junho/2019
*/

/** MEUS HEADERS FILE */
#include "verificadorcpf.h"
#include "data.h"
#include "DefaultAPISystem.h"

/** APIS DA LINGUAGEM **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

//Estrutura Colaborador
typedef struct colaborador
{
  char Nome[41];
  char CPF[13];
  char Sexo;
  char DataNascimento[13];
  char Nacionalidade[40];
  float Salario;
  int Dependentes;

  char Departamento[15];
  char Escolaridade[15];

};

/**GLOBAIS**/
const float SALARIO_MINIMO = 998.0;
char endereco[] = "Cad_Colabores.txt";


void adcionarColaborador(char *endereco);
void visualizarDados(char *endereco);

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese");
  int Opcao;

  do
  {
    system("clear");
    printf("\tLABORATÓRIO FARMACÊUTICO LÓGICA I\n");
    printf("\tSistema de Recursos Humanos\n\n");

    menuAplicacao();

    printf("\nOpcao: ");
    scanf("%d", &Opcao);
    getchar();

    if(Opcao == 0)
      exit(1); //Finaliza a aplicação

    switch(Opcao)
    {
      case 1:
        system("clear");
        printf("Entrou 1\n");
        getchar();
      break;
      case 2:
      break;
      case 3:
        system("clear");
        printf("Adcionar Colaboradores: \n");
        printf("---------------------------\n");
        printf("Para finalizar o programa digite fim no nome.");
        getchar();

        system("clear");

        adcionarColaborador(endereco);

      break;
      case 4:
      break;
      case 5:
        system("clear");
        printf("Visualizar Colaboradores: \n");
        printf("---------------------------\n");
        visualizarDados(endereco);
        getchar();
      break;
      default:
        printf("Opção Inválida!\n");
      break;
    }

  } while(1);
  return 0;
}


///Funcionalidades da aplicação:
void adcionarColaborador(char *endereco)
{
  //CHAMADA DO ARQUIVO
  FILE *Arquivo = fopen(endereco, "ab");

  //Verificação da abertura do arquivo
  if(Arquivo == NULL)
  {
    printf("Impossível abrir o arquivo\n");
    getchar();
    exit(1);
  }

  //Variável referente aos departamentos e escolaridade
  char opcao;
  //Instância o colaborador na memória
  struct colaborador Colaborador;

  while(strcasecmp(Colaborador.Nome, "fim") != 0)
  {
    system("clear");
    setbuf(stdin, NULL);

    printf("\tLABORATÓRIO FARMACÊUTICO LÓGICA I\n");
    printf("\tSistema de Recursos Humanos\n\n");

    printf("Nome: ");
    fgets(Colaborador.Nome, 40, stdin);
    Colaborador.Nome[strcspn(Colaborador.Nome, "\n")] = '\0';
    while(strlen(Colaborador.Nome) < 3 || strlen(Colaborador.Nome) > 40)
    {
        printf("Mensagem de erro: O nome deve ter no mínimo 3 e no máximo 40 caracteres.\n");
        printf("Nome: ");
        fgets(Colaborador.Nome, 41, stdin);

        Colaborador.Nome[strcspn(Colaborador.Nome, "\n")] = '\0';
      }//Fim da validação do nome:


    if(strcasecmp(Colaborador.Nome, "fim") != 0)
    {
      setbuf(stdin, NULL);

      printf("CPF: ");
      fgets(Colaborador.CPF, 13, stdin);
      Colaborador.CPF[strcspn(Colaborador.CPF, "\n")] = '\0';

      while(verificaCPF(Colaborador.CPF) == 0)
      {
        setbuf(stdin, NULL);
        printf("\nMensagem de erro: O CPF deve ser valido.\n");
        printf("CPF: ");
        fgets(Colaborador.CPF, 13, stdin);
        Colaborador.CPF[strcspn(Colaborador.CPF, "\n")] = '\0';
      }//Fim validação CPF

      setbuf(stdin, NULL);
      printf("Sexo [M | F]: ");
      scanf("%c", &Colaborador.Sexo);
      getchar();
      Colaborador.Sexo = toupper(Colaborador.Sexo);
      while(Colaborador.Sexo != 'M' && Colaborador.Sexo != 'F')
      {
        setbuf(stdin, NULL);
        printf("\nMensagem de erro: Sexo deve ser M ou F.\n");
        printf("Sexo [M | F]: ");
        scanf("%c", &Colaborador.Sexo);
        getchar();
        Colaborador.Sexo = toupper(Colaborador.Sexo);
      }//FIM VALIDAÇÃO SEXO

      setbuf(stdin, NULL);

      printf("Data de nascimento (dd/mm/yyyy): ");
      fgets(Colaborador.DataNascimento, 13, stdin);
      Colaborador.DataNascimento[strcspn(Colaborador.DataNascimento, "\n")] = '\0';
      while(validaData(Colaborador.DataNascimento) == 0 || idadeValida(Colaborador.DataNascimento) == 0)
      {
        setbuf(stdin, NULL);
        printf("Data de nascimento (dd/mm/yyyy): ");
        fgets(Colaborador.DataNascimento, 13, stdin);
        Colaborador.DataNascimento[strcspn(Colaborador.DataNascimento, "\n")] = '\0';
      }//Fim validação datas

      getchar();
      setbuf(stdin, NULL);

      printf("Nacionalidade: ");
      fgets(Colaborador.Nacionalidade, 40, stdin);
      Colaborador.Nacionalidade[strcspn(Colaborador.Nome, "\n")] = '\0';

      //Tamanho da nacionalida sempre vai ser 1 a mais por causa do caracter de \0
      while(strlen(Colaborador.Nacionalidade) < 3 || strlen(Colaborador.Nacionalidade) > 30)
      {
        printf("\nMensagem de erro: A nacionalidade deve ter no mínimo 2 e no máximo 30 caracteres\n");
        printf("Nacionalidade: ");
        fgets(Colaborador.Nacionalidade, 40, stdin);
        Colaborador.Nacionalidade[strcspn(Colaborador.Nome, "\n")] = '\0';

      }//Fim validação Nacionalidade

      setbuf(stdin, NULL);

      printf("Salário: ");
      scanf("%f", &Colaborador.Salario);

      while(Colaborador.Salario < SALARIO_MINIMO || Colaborador.Salario > (SALARIO_MINIMO * 50))
      {
        printf("\nMensagem erro: Salário deve ser maior do que 1 e menor do que 50 sálarios minimos.\n");
        printf("Salário: ");
        scanf("%f", &Colaborador.Salario);
      }//Fim validação sálario segundo regra de negócio

      setbuf(stdin, NULL);

      printf("Dependentes: ");
      scanf("%d", &Colaborador.Dependentes);

      while(Colaborador.Dependentes < 0 || Colaborador.Dependentes > 20)
      {
        printf("\nMensagem de erro: Os dependentes devem estar entre 0 e 20.\n");
        printf("Dependentes: ");
        scanf("%d", &Colaborador.Dependentes);
      }//Fim validação de número de dependentes

      setbuf(stdin, NULL);
      menuDepartamentos();
      printf("\nDepartamento: ");
      scanf("%c", &opcao);
      getchar();
      opcao = toupper(opcao);
      while(opcao != 'I' && opcao != 'L' && opcao != 'A' && opcao != 'T' && opcao != 'S')
      {
        setbuf(stdin, NULL);
        printf("\nMensagem de erro: Opções válidas para departamento (I L A T S).\n");
        printf("\nDepartamento: ");
        scanf("%c", &opcao);
        getchar();
        opcao = toupper(opcao);
      }

      //Função para tribuir a opção ao valor do departamento:
      atribuicaoDPT(opcao, Colaborador.Departamento);
      //Fim da validação dos departamentos:

      setbuf(stdin, NULL);
      menuEscolaridade();
      printf("\nEscolaridade: ");
      scanf("%c", &opcao);
      getchar();
      opcao = toupper(opcao);
      while(opcao != 'E' && opcao != 'G' && opcao != 'M' && opcao != 'D')
      {
        setbuf(stdin, NULL);
        printf("\nMensagem de erro: Opções válidas para escolaridade(E G M D).\n");
        printf("\nEscolaridade: ");
        scanf("%c", &opcao);
        getchar();
        opcao = toupper(opcao);
      }

      //Função para atribuir opções a escolaridade
      atribuicaoEscolaridade(opcao, Colaborador.Escolaridade);
      //Fim validação Escolaridade
      setbuf(stdin, NULL);

      system("clear");

      printf("Deseja armazenar os dados (S/n)? ");
      scanf("%c", &opcao);
      getchar();
      opcao = toupper(opcao);

      while(opcao != 'S' && opcao != 'N')
      {
        system("clear");
        printf("\nMensagem de erro: Apenas S ou N.\n");
        printf("Deseja armazenar os dados (S/n)? ");
        scanf("%c", &opcao);
        getchar();
        opcao = toupper(opcao);
      }

    if(opcao == 'S')
    {
      int result = fwrite(&Colaborador, sizeof(struct colaborador), 1, Arquivo);
      if(result == 1)
      {
        system("clear");
        printf("Dados Armazenados com sucesso! Pressione Enter\n");
        getchar();
      }
      else
      {
        printf("Ocorreu algum erro! Pressione Enter\n");
        getchar();
      }
    }
    else
    {
      printf("Tem certeza? Os dados digitados serão perdidos. (S/ n) ");
    }

    }//Fim do if

  }//Fim do while mais externo

  //Fechamento do arquivo
  fclose(Arquivo);

}

void visualizarDados(char *endereco)
{
  int contador = 0;
  struct colaborador Colaborador;
  FILE *Arquivo;
  Arquivo = fopen(endereco, "rb");
  if(Arquivo == NULL)
  {
    printf("Impossível abrir o arquivo para leitura\n");
    getchar();
    exit(1);
  }

  int result = fread(&Colaborador, sizeof(struct colaborador), 1, Arquivo);

  while(!feof(Arquivo))
  {
    if(result == 1)
    {
      printf("ID: %d\n", ++contador);
      printf("Nome: %s\n", Colaborador.Nome);
      printf("CPF: %s\n", Colaborador.CPF);
      printf("Sexo: %c\n", Colaborador.Sexo);
      printf("Data Nascimento: %s\n", Colaborador.DataNascimento);
      printf("Departamento: %s\n", Colaborador.Departamento);

      printf("\n---------------------------\n");
      result = fread(&Colaborador, sizeof(struct colaborador), 1, Arquivo);

    }
  }
  fclose(Arquivo);
}
