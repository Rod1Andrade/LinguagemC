///
/// @author: Rodrigo Moreira Pires de Andrade
///
/// Validação datas, incluindo anos bissexto e meses com 30 e 31 dias
/// ////////////////////////////////////////////////////////

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

/**
* // @author: Rodrigo Andrade
* // @param: Ano
* // return: 0 se o ano não for bissexto
* // return: 1 se o ano for bissexto
*/
bissexto(int ano);

/**
* @author: Rodrigo Andrade
* @param: string contendo a data
* @return: data valida como 1 e data invalida como 0
*/
int validaData(char *Data);

///FUNÇÃO A SER ALTERADA: pertence a regra de negócio
int idadeValida(char *Data);


#endif // DATA_H_INCLUDED
