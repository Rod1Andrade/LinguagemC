#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "Pontos.h"

struct pointer{
  float x;
  float y;
};

int main(int argv, char *argc[]){
  
  Pointer *p, *q;

  p = NewPointer(10, 11);
  q = NewPointer(11, 21);
  
  FreePointer(p);
  FreePointer(q);
  
  return 0;
}

//Contrutor
Pointer* NewPointer(Pointer* p, float x, float y){
  
  //Alocar espaço de memória para o Pointer com cast implicito
  Pointer* p = (Pointer*) malloc(sizeof(Pointer));

  if(p != NULL){
    p->x = x;
    p->y = y;
  }
  return p;
}

//Libera espaço de memória Alocado pela função malloc
void FreePointer(Pointer* p){
  free(p);
}
