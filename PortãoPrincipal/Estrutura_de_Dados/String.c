#include <stdio.h>

int main(int argv, char *argc[])
{
  
  //Leitura com puts
  static char re[] = "Largato";
  puts(re);
  puts(&re[0]);
  putchar('\n');
  
  //Utilizando Gets para capturar a sequência de char.
  char str[80];
  gets(str);

  printf("%s", str);

  putchar('\n');
  return 0;
}
