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

//Estrutura Colaborador
typedef struct
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

} colaborador;

/**GLOBAIS**/
const float SALARIO_MINIMO = 998.0;

int main(int argc, char **argv)
{
  //CHAMADA DO ARQUIVO
  FILE *Arquivo = fopen("Cad_Colabores.txt", "ab");

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
  colaborador Colaborador;
  printf("%zu\n", sizeof(colaborador));

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
        printf("\n\Mensagem de erro: Opções válidas para departamento (I L A T S).\n");
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

    }//Fim do if

    ///TODO: Armazenar dados em arquivo:

  }//Fim do while mais externo

  //Fechamento do arquivo
  fclose(Arquivo);

  return 0;
}
