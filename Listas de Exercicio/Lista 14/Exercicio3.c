/***
 * @author: Rodrigo Andrade 
 *
 * Exercício: Faça um programa que mostre um menu com 10 porções de alimentos que uma
 * pessoa pode escolher para comer e a opção Sair.
 * Você deverá consultar 10 porções de comida com suas respectivas calorias.
 * No seu menu as calorias das porções não devem ser mostradas.
 * Depois que a pessoa escolher a porção, seu programa deverá mostrar a quantidade
 * de calorias da porção.
 * Depois o programa deve dizer que a pessoa precisará fazer uma caminhada ou corrida
 * para gastar as calorias adquiridas com a porção escolhida.
 * O programa deve perguntar qual o peso da pessoa e em qual velocidade(em KM/H) a
 * pessoa vai caminhar ou correr.
 * Por fim o programa deverá escrever quantos minutos a pessoa deverá caminhar ou
 * correr para gastar as calorias consumidas.
 * 
 *
 * Formula: 
 * Gasto Calorico por Minuto = Velocidade * Peso * 0.0175
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estruturas:
typedef struct 
{
  char Nome[30];
  char padd[sizeof(float)];
  float Caloria;
} porcoes;

//Parametrização de Funções:
void armazenarPorcoes();
void LeituraPorcoes();

int main(void)
{

  setlocale(LC_ALL, "Portuguese");

  short escolha;
  printf("Você desejar ir para o menu ou adcionar porções? \n1 - Menu 2 - Porções : \n");
  scanf("%hd", &escolha);
  if(escolha == 1)
  {
    system("clear");
    LeituraPorcoes();
  }
  else
  {
    setbuf(stdin, NULL);
    printf("Você deseja realmente adcionar porções, se fizer isso, o que já foi armazenado, será excluído\n");
    printf("1 - Sim 2 -Não\n");
    scanf("%hd", &escolha);
    if(escolha == 1)
    {
      system("clear");
      armazenarPorcoes();

      system("clear");
      LeituraPorcoes();
    }
    else
    {
      system("clear");
      LeituraPorcoes();
    }
  }
  return 0;
}

void armazenarPorcoes()
{ 
  setbuf(stdin, NULL);

  //Arquivo para Armazenar Porções: 
  FILE *arquivo;
  arquivo = fopen("Porcoes.txt", "wb");

  const short tamanho = 10;
  porcoes Porcoes[tamanho];

  for(int i = 0; i < tamanho; i++)
  {
    printf("Porção: ");
    fgets(Porcoes[i].Nome, 30, stdin);
    Porcoes[i].Nome[strlen(Porcoes[i].Nome) - 1] = '\0';

    setbuf(stdin, NULL);

    printf("Caloria: ");
    scanf("%f", &Porcoes[i].Caloria);

    setbuf(stdin, NULL);
  }

  int QuantidadeArmazenada = fwrite(Porcoes, sizeof(porcoes), tamanho, arquivo);
  if(QuantidadeArmazenada != tamanho)
    printf("Erro ao armazenar dados\n");

  fclose(arquivo);

}

/*
 * Resolução do problema está todo nessa função
 * **/
void LeituraPorcoes()
{

  FILE *arquivo;
  arquivo = fopen("Porcoes.txt", "rb");

  const short tamanho = 10;
  porcoes Porcoes[tamanho];

  int totalLido = fread(Porcoes, sizeof(porcoes), tamanho, arquivo);
  if(totalLido != tamanho)
    printf("Impossível ler todos os arquivos\n");

  float Peso, Velocidade, Min;
  short opcao;

  do
  {
    for(int i = 0; i < tamanho; i++)
      printf("%d - %s\n", i, Porcoes[i].Nome);

    printf("Sair -1\n");
    printf("Opção: ");
    scanf("%hd", &opcao);

    if(opcao == -1)
      break;

    printf("\n\n");
    switch(opcao)
    {
      case 0:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 

      case 1:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break;

      case 2:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 
      case 3:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 

      case 4:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 

      case 5:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 
      case 6:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 
      case 7:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 
      case 9:
        system("clear");
        printf("%s\n", Porcoes[opcao].Nome);
        printf("Quantidade de calorias: %.2f\n", Porcoes[opcao].Caloria);
        printf("\nVocê deverá fazer uma caminhada ou corrida para gastar as calorias adquiridas.\n\n");
        printf("Digite seu peso: ");
        scanf("%f", &Peso);
        printf("Em qual velocidade vai caminhar/correr: ");
        scanf("%f", &Velocidade);
        Min = Porcoes[opcao].Caloria / (Velocidade * Peso * 0.0175);

        printf("Você deverá correr ou caminhar por: %.2f\n", Min);
        setbuf(stdin, NULL);
        getchar();

        system("clear");
        break; 

      defautl:
        printf("Opção Inválida\n");
        getchar();
        setbuf(stdin, NULL);
        break;
    }
  }while(1);

  fclose(arquivo);
}
