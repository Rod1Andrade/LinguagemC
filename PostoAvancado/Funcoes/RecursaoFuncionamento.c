/**
 * @author: Rodrigo Andrade
 * Descrição do ráciocinio de empilhamento de função, em uma função 
 * responsável por realizar um cálculo fatorial.
 *
 * Quando uma função chama outra a função 
 * acontece um processo de empilhamento de chamadas
 * até que a última função seja chamada, então por outro lado
 * começa-se um processo de desempilhamento, e nesse processo
 * se retorna os valores em ordem contrária para a função que o chamou:
 *
 * Exemplo
 *
 * 4! = 4 * 3!
 * 3! = 3 * 2!
 * 2! = 2 * 1!
 * 1! = 1 * 0!
 * 0! = 1 -> Caso base;
 *
 * Em c:
 *
 * <tipo> nome(<tipo> n)
 * {
 *    if(n == 0)
 *      return 1;
 *    else
 *      return n * <tipo>(n-1);  
 * }
 *
 *
 * */

<tipo> fatorial(<tipo> n) {

     if(n == 0)
       return 1;
     else
       return n * <tipo>(n-1);
}

//Na memória

empilhamento:
int x = fatorial(4);

se 4 == 0
  retorna 1
senão
  retorn 4 * fatorial(4-1)

//Fatorial(4-1)
fatorial(3):
se 3 == 0
  retorna 1
senão 
  retorne 3 * fatorial(3-1)

//fatorial(3-1)
fatorial(2)
se 2 == 0
  retorna 1
senão
  retorna 2 * fatorial(2-1)

//fatorial(2-1)
fatorial(1)
se 1 == 0
  retorna 1
senão 
  retorna 1 * fatorial(1-1)

//fatorial(1-1)
fatorial(0)

se 0 == 0
  retorna 1


/*
 * Nesse ponto do programa, acaba-se a recursividade,
 * o processo de empilhamento está finalizado por ter 
 * atingindo um parâmetro de para nas chamadas das funções
 *
 * Agora as funções vao retornar os valores para a função na qual a chamou
 *
 * **/

Desempilhamento: 
retorna 1
retorna 1 * 1
retorna 1 * 1 * 2
retorna 1 * 1 * 2 * 3
retorna 1 * 1 * 2 * 3 * 4

retorna 4 para a váriavel inteira x contida na primeira função que chamou
a função main.







 
 
