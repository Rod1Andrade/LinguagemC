#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[])
{
  
  for(int i = 0; i < argv; i++)
    printf("argc[%d] = %s\n", i, *(argc+i));
  /**
   * Parâmetro da função: 
   * Permite ao programador passar uma informação de um trecho de 
   * código para dentro de uma função.
   *
   * */
  return 0;
}
