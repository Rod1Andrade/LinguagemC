#include <stdlib.h>
#include <stdio.h>

struct Hora
{
  int hora;
  int minuto;
  int segundo;
};

int main(void)
{

  struct Hora antes, agora, *depois;
  depois = &agora;

  //1 - Para acessar um ponteiro de um tipo de estrutura (*s).valor;
  (*depois).hora = 13;
  (*depois).minuto = 43;
  (*depois).segundo = 11;

  //2 - Para acessar um ponteiro de um tipo de estrutura (->) valor
  depois->hora = 23;
  depois->minuto = 14;
  depois->segundo = 14;


  antes.hora = 100 + depois->segundo;
  antes.minuto = agora.hora + depois->minuto;
  antes.segundo = depois->minuto + depois->segundo; 

  printf("%d:%d:%d\n", antes.hora, antes.minuto, antes.segundo);
  printf("%d:%d:%d\n", agora.hora, agora.minuto, agora.segundo);

}








