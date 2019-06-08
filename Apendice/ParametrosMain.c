#include <stdio.h>
#include <stdlib.h>

///Os parametros da função main, virão do prompot da linha de comando do sistema operacional
///Função principal, que inicia a execução do programa.
int main(int argc, char *argv[])
{
  /**
   *
   * int argc: Valor que indica o número de parametros com os a função 
   * main foi chamada (argc >= 1)
   *
   * char *argv[]: Ponteiro para um vetor contendo argc strings
   * é um dos parametros para a função main();
   *
   * argv[0] sempre aponta para o nome do programa
   * */

  //Exemplo: Programa para calcular n números inteiros passado como parâmetro da função main.
  int totalSoma = 0;
  if(argc == 1)
    printf("Programa %s sem parametros.\n", argv[0]);
  else
    for(int i = 1; i < argc; i++)
      totalSoma += atoi(argv[i]); 

  printf("Resultado: %d\n", totalSoma);
  return 0;
}
