#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cdr(char *list)
{
  *rindex(list, ')') = ' ';
  return 1+index(list, '(');
}

char *car(char *list)
{
  return strtok(list, "() ");
}

int main(void)
{
  char list_test[]=" (a b ( e (f)))";
  char pop[10];
  strcpy(pop, car(list_test));
  printf("%s", pop);
  return 0;
}
