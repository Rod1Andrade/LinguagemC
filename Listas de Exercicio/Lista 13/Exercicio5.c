/**
 * Faça um programa para fazer o cadastro de um cliente e depois escrever o texto
 * um que contém as informações lidas e textos adicionais. Até que seja digitado Sair no 
 * nome.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Área Struct
typedef struct
{
  char Rua[40];
  int Numero;
  char Bairro[40];
  char Cidade[40];
  char Estado[40];
  char Pais[40];

} endereco;

typedef struct 
{
  char Nome[40];
  char EstadoCivil[40];
  char Profissao[40];
  char NomeMae[40];
  short Idade;

  endereco ender;
  
} cliente;

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  //Instanciando Pessoa: 
  cliente Cliente;

  while(1)
  {
    printf("CADASTRO CLIENTES: \n");
    printf("Nome: ");
    fgets(Cliente.Nome, 40, stdin);

    Cliente.Nome[strlen(Cliente.Nome) - 1] = '\0';

    if(strcasecmp(Cliente.Nome, "sair") == 0)
      break;

    printf("\n");

    printf("ENDEREÇO: \n");
    printf("Rua: ");
    fgets(Cliente.ender.Rua, 40, stdin);
    Cliente.ender.Rua[strlen(Cliente.ender.Rua) - 1] = '\0';

    printf("Número: ");
    scanf("%d", &Cliente.ender.Numero);
    setbuf(stdin, NULL);

    printf("Bairro: ");
    fgets(Cliente.ender.Bairro, 40, stdin);
    Cliente.ender.Bairro[strlen(Cliente.ender.Bairro) - 1] = '\0';

    printf("Cidade: ");
    fgets(Cliente.ender.Cidade, 40, stdin);
    Cliente.ender.Cidade[strlen(Cliente.ender.Cidade) - 1] = '\0';


    printf("Estado: ");
    fgets(Cliente.ender.Estado, 40, stdin);
    Cliente.ender.Estado[strlen(Cliente.ender.Estado) - 1] = '\0';


    printf("Pais: ");
    fgets(Cliente.ender.Pais, 40, stdin);
    Cliente.ender.Pais[strlen(Cliente.ender.Pais) - 1] = '\0';

    printf("\nCOMPLEMENTO: \n");
    printf("Idade: ");
    scanf("%hd", &Cliente.Idade);

    setbuf(stdin, NULL);

    printf("Estado Civil: ");
    fgets(Cliente.EstadoCivil, 40, stdin);
    Cliente.EstadoCivil[strlen(Cliente.EstadoCivil) -1] = '\0';
     
    printf("Profissão: ");
    fgets(Cliente.Profissao, 40, stdin);
    Cliente.Profissao[strlen(Cliente.Profissao) -1] = '\0';

    printf("Mãe: ");
    fgets(Cliente.NomeMae, 40, stdin);
    Cliente.NomeMae[strlen(Cliente.NomeMae) -1] = '\0';

    //Saída formatada na tela: 
    printf("\n%s, filho de %s, %hd anos, %s, %s,\nresidente na Rua %s, N. %d, Bairro %s, %s, %s,%s\n\n",
        Cliente.Nome, Cliente.NomeMae, Cliente.Idade, Cliente.EstadoCivil, Cliente.Profissao,
        Cliente.ender.Rua, Cliente.ender.Numero, Cliente.ender.Bairro, Cliente.ender.Cidade,
        Cliente.ender.Estado, Cliente.ender.Pais);

    setbuf(stdin, NULL);

    getchar();
    system("clear");
    
  }
  printf("Cadastro Encerrado!\n");
  return 0;
}
