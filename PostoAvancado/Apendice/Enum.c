#include <stdio.h>
#include <stdlib.h>

//ENUM é um conjunto de constantes com identificadores
enum semana { Domingo, Segunda, Terca, Quarta, Quita, Sexta, Sabado};

int main(int argv, char *argc[])
{
  
  //Enumeração: 

  /**
   * Forma geral:
   * enum nome_enum = { lista de identificadores };
   * */
  
  //Exemplo: 
  
  enum semana s;

  s = Segunda;
  printf("Valor = %d\n", s);

  return 0;
}
