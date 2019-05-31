#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  char Animal[30];
  char Caracteristica[30];
  char NomeAvatar[30];

} avatar;

void strToLower(char *str);

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, "Portuguese");

  //Intância do avatar
  avatar Avatar;
  while(1)
  {
    system("clear");
    printf("\tINFORME OS DADOS PARA SEU AVATAR\n");

    printf("Animal: ");
    fgets(Avatar.Animal, 30, stdin);
    Avatar.Animal[strlen(Avatar.Animal) - 1] = '\0';

    printf("Característica: ");
    fgets(Avatar.Caracteristica, 30, stdin);
    Avatar.Caracteristica[strlen(Avatar.Caracteristica) - 1] = '\0';

    strcpy(Avatar.NomeAvatar, Avatar.Animal);
    strcat(Avatar.NomeAvatar, "_");
    strcat(Avatar.NomeAvatar, Avatar.Caracteristica);

    strToLower(Avatar.NomeAvatar);
    printf("Nome do avatar: %s\n", Avatar.NomeAvatar);
    
    if(strlen(Avatar.NomeAvatar) <= 15)
    {
      printf("Avatar Aceito!\n");
      break;
    }
    else
    {
      printf("Nome do avata supero o limite de 15 caracteres, informe novamente!\n");
      getchar();
      setbuf(stdin, NULL);
    }

  }

}

void strToLower(char *str)
{
  char aux;
  for(int i = 0; str[i] != '\0';i++)
  {
    aux = tolower(str[i]);
    str[i] = aux;
  }
}
