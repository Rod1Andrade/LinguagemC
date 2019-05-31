#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int main(int argv, char *argc[])
{

  setlocale(LC_ALL, "Portuguese");

  unsigned short Opcao;
  bool Boolean = true;

  //Contagem de votos Manoel Rodrigues
  unsigned long VotosManoel = 0;

  //Contagem de votos Carlos Luz
  unsigned long VotosCarlos = 0;

  //Contagem de votos Nulos
  unsigned long VotosNulos = 0;

  //Contagem de votos Nulos
  unsigned long VotosBrancos = 0;
  
  //Contador de votos Computados
  unsigned long Votos = 0;

  while(Boolean)
  {
  
   system("clear");
  
   printf("\tE L E I Ç Õ E S 2 0 1 8\n");
   printf("1. Candidato Manoel Rodrigues\n");
   printf("2. Candidato Carlos Luz\n");
   printf("4. Nulo\n");
   printf("5. Branco\n");
   printf("6. Relatório\n");
   printf("7. Sair\n");
   printf("Digite a opção: ");
   scanf("%hu", &Opcao);
    
   switch(Opcao)
   {
    case 1:
      VotosManoel++;
      Votos++;
      break;
    case 2:
      VotosCarlos++;
      Votos++;
      break;
    case 4:
      VotosNulos++;
      Votos++;
      break;
    case 5:
      VotosBrancos++;
      Votos++;
      break;
    case 6:

      system("clear");
      printf("\tRelatório\n"); 

      //Votos computados para cada representante
      printf("Candidato Manoel Rodrigues: %lu Votos Válidos\n", VotosManoel); 
      printf("Candidato Carlos Luz: %lu Votos Válidos\n", VotosCarlos); 

      //Votos nulos --> total votos 100% | Votos nulos x => x = votos nulos * 100 / total votos
      float PorcentNulos = (VotosNulos * 100) / Votos;
      printf("%.2f %% votos nulos\n", PorcentNulos);

      //Votos Brancos --> total votos 100% | Votos nulos x => x = votos Brancos * 100 / total votos
      float PorcentBrancos = (VotosBrancos * 100) / Votos;
      printf("%.2f %% votos Brancos\n", PorcentBrancos);

      //Vencedor com mais votos
      if(VotosManoel > VotosCarlos)
      {
        printf("Manoel Rodrigues é o vencedor, com %lu dos votos válidos, e com uma diferença de: %lu.\n", VotosManoel, VotosManoel-VotosCarlos);
      }
      else if(VotosManoel == VotosCarlos)
      {
        printf("Eleição segue empatada com: %lu de votos para Manoel Rodrigues e %lu de votos para Carlos Luz\n", VotosManoel, VotosCarlos);
      }
      else
      {
        printf("Carlos luz é o vencedor, com %lu dos votos válidos, e com uma diferença de: %lu\n", VotosCarlos, VotosCarlos-VotosManoel);
      }

      setbuf(stdin, NULL);
      getchar();

      break;
    case 7:
      Boolean = false;
      break;
    default:
      printf("Opção Inválida\nPressione ENTER para continuar\n");
      setbuf(stdin, NULL);
      getchar();
      break;

   }

   setbuf(stdin, NULL);

  }

  return 0;
}
