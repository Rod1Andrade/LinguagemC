/**
 * Uma struct pode ser passada de dois modos para uma função:
 *
 * Por valor:
 *    * Deste modo você passa um único campo, 
 *    e o tipo do campo deve ser compativel com o tipo
 *    dentro do parâmetro da função.
 *
 * Por referência: 
 *    * Deste modo você pode passar tanto um campo como a struct toda,
 *    através de um ponteiro para essa estrutura.
 *
 *    forma geral:
 *    * -->  <tipo> nome(struct <tipo> *nome)
 *
 * */
#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
  int idade;
  float altura;
};

//Passagem do campo por valor: 
void imprimeCampo(int n)
{
  printf("Valor do campo: %d\n", n);
}

//Passagem do campo por referência:
void somaCampo(int *n)
{
  (*n)++;
  printf("n = %d\n", *n);
}

//Passagem da struct por referência:
void imprimeStruct(struct pessoa *p)
{
  (*p).altura = 1.66; //Preferivel utilizar o operador (->);
  printf("Idade = %d\n", (*p).idade);
}

//Usando o operador seta, você formata melhor os ponteiros para a estrutura: 
void atribui(struct pessoa *p)
{
  p->idade = 1001;
  p->altura = 1.66;
}

int main(void)
{
  struct pessoa Pessoa; 
  Pessoa.idade = 19;

  //Por referência você deve passar o endereço do campo: 
  somaCampo(&Pessoa.idade);

  //Por valor, como o campo não vai ter seu valor original alterado, pode se passar somente o valor, que será copiado.
  imprimeCampo(Pessoa.idade);

  //struct passada por referência para a função (endereço):
  atribui(&Pessoa);
  imprimeStruct(&Pessoa);

  return 0;
}
