Deve se estebelecer um critério de parada para as chamadas recursivas da função.
Caso contrário terá um looping infinito que forma uma pilha, até um estouro de 
posições de memória. (!CUIDADO!)

  /***/

  Parametros da chamada recursiva:
  devemos sempre atualizar o valor do parâmetro passado,
  de forma que a recursão chegue a um término (critério de parada).

  exemplo:

  se n == 0
    return 1; (Aqui parou de chamar a função, nosso critério de parada)
 caso contrário:
    return n * funcao(n-1);

note que o valor chamado no parâmetro sofre um decremento, a fim de que se chegue no
critério de para genérico.

obs:
Algoritimos recursivos tendem a necessitar de mais tempo e espaço 
do que algoritimos recursivos:

Algoritimo recursivo da sequência fibonacci não é eficiente.(evite duas chamadas ou mais recursivas)

A sequência é dada pela soma dos n-1 + n-2 dois termos

<tipo> fibonacci(<tipo> n)
{
  if(n == 0 || n == 1)
    return n;
  else
    return fibonacci(n-1) + fibonacci(n+2);
}


