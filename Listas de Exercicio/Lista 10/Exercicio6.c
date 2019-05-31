#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>

int main(int argv, char *argc[])
{
  setlocale(LC_ALL, "Portuguese");

  //Informações Primordiais
  unsigned short NumEspectadores = 0;
  unsigned short Idade;
  char Opniao;

  //Média das idades de pessoas que responderam Excelente
  int IdadeExcelente = 0, QtdExcelente = 0;
  float MediaIdades;

  //Quantidade de Pessoas que responderam Regular
  short QtdRegular = 0;

  //Porcetagem de pessoas que responderam bom entre todos os espectadores
  float Porcentagem;
  short QtdBom = 0;

  //Quantas Pessoas com mais de 18 anos responderam Péssimo
  short QtdPessimo = 0;

  while(NumEspectadores < 20)
  {
    system("clear");

    printf("Idade: ");
    scanf("%u", &Idade);

    setbuf(stdin, NULL);
    
    printf("E - Excelente\n");
    printf("B - Bom\n");
    printf("R - Regular\n");
    printf("P - Péssimo\n");

    printf("Opcao: "); 
    scanf("%c", &Opniao);

    Opniao = toupper(Opniao);

    switch(Opniao)
    {
      case 'E':
        IdadeExcelente += Idade;
        QtdExcelente++;
        NumEspectadores++;
      break;
      case 'B':
        QtdBom ++;
        NumEspectadores++;
      break;
      case 'R':
        QtdRegular++;
        NumEspectadores++;
      break;
      case 'P':
        if(Idade > 18)
        {
          QtdPessimo++;
        }
        NumEspectadores++;
      break;
      default:
        printf("Opção Invalida Digite novamente\n");
        sleep(1);
      break; 
    }

  }//Fim do While
  
  //Média das Idades que responderam excelentes
  if(IdadeExcelente != 0)
  {
    MediaIdades = IdadeExcelente / QtdExcelente;
    printf("Média das idades que responderam Excelente: %.2f\n", MediaIdades); 
  }

  //Quantidade de pessoas que responderam regular
  if(QtdRegular != 0)
    printf("Quantidade de pessoas que responderam regular: %d\n", QtdRegular);

  //Porcentagem de pessoas que responderam bom entre todos
  if(QtdBom != 0)
  {
    Porcentagem = (QtdBom*100) / NumEspectadores;
    printf("Porcetagem de pessoas que responderam bom entre todos: %.1f%%\n", Porcentagem);
  }

  //Quantas pessoas com mais de 18 anos responderam Péssimo:
  if(QtdPessimo != 0)
    printf("Quantas pessoas com mais de 18 anos responderam Péssimo: %d\n", QtdPessimo);

  return 0;
}
