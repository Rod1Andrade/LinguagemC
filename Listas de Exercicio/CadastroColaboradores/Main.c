#include "verificadorcpf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ESTRUTURA COLABORADOR **/
typedef struct
{
  char Nome[41];
  char CPF[13];
  char Sexo;
  char DataNascimento[11];
  float Salario;
  int Dependentes;

  char Departamento[15];
  char Escolaridade[15];

} colaborador;

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
    fgets(Colaborador.Nome, 41, stdin);
    Colaborador.Nome[strlen(Colaborador.Nome) -1 ] = '\0';

    if(strcasecmp(Colaborador.Nome, "fim") != 0)
    {
      while(strlen(Colaborador.Nome) < 3 || strlen(Colaborador.Nome) > 40) 
      {
        printf("Mensagem de erro: O nome deve ter no mínimo 3 e no máximo 40 caracteres.\n");
        printf("Nome: ");
        fgets(Colaborador.Nome, 41, stdin);

        Colaborador.Nome[strlen(Colaborador.Nome) -1 ] = '\0';
      }//Fim da validação do nome: 

      printf("CPF: ");
      fgets(Colaborador.CPF, 13, stdin);
      Colaborador.CPF[strlen(Colaborador.CPF) -1 ] = '\0';

      while(verificaCPF(Colaborador.CPF) == 0)
      {
        printf("\nMensagem de erro: O CPF deve ser valido.\n");
        printf("CPF: ");
        fgets(Colaborador.CPF, 13, stdin);
        Colaborador.CPF[strlen(Colaborador.CPF) -1 ] = '\0';
      }//Fim validação CPF 

    }//Fim do if
  }//Fim do while mais externo

  //Fechamento do arquivo
  fclose(Arquivo);

  return 0;
}

