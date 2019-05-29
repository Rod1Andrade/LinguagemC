#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 
  //Inicialização do vetor de caracter (string)
  char palavra[30];

  //Recebendo do úsuario a palavra digitada: 
  printf("Digite uma palavra: ");
  scanf("%s", &palavra); //Palavra lida até digitar Enter ou Espaço
  printf("Palavra Digitada: %s\n\n", palavra);

  setbuf(stdin, NULL);

  printf("Digite uma palavra: ");
  gets(palavra);//Termina a leitura quando se digita o ENTER
  printf("Palavra Digitada: %s\n", palavra);

  return 0;
}
