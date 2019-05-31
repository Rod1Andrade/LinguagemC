/**
 * Faça um programa para ler o usuário e senha de uma pessoa enquanto o usuário
 * não for igual a SIUEG e a senha igual a LOGICA1. Quando o usuário e senha
 * estiverem corretos o programa deve imprimir ACESSO LIBERADO!
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct 
{
  char Login[40];
  char Senha[40];
} usuario;

int main(void)
{

  setlocale(LC_ALL, "Portuguese");

  //Strings constantes para comparação: 
  const char UsuarioPadrao[40] = "SIUEG";
  const char SenhaPadrao[40] = "LOGICA1";

  //Defininido a Estrutura Usuario:
  usuario Usuario;

  while(1)
  {
    printf("Usuário: ");
    fgets(Usuario.Login, 40, stdin);

    printf("Senha: ");
    fgets(Usuario.Senha, 40, stdin);
    
    //Convertendo o caracter \n pelo \0
    Usuario.Login[strlen(Usuario.Login) - 1] = '\0';
    Usuario.Senha[strlen(Usuario.Senha) - 1] = '\0';

    if((strcmp(Usuario.Login, UsuarioPadrao) && strcmp(Usuario.Senha, SenhaPadrao)) == 0)
    {
      printf("\nACESSO LIBERADO\n");
      break;
    }
    else
    {
      printf("\nUsuário ou Senha inválidos!\n");
      setbuf(stdin, NULL);
    }

  }

  return 0;
}


