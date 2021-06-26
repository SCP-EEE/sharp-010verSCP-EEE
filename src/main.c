#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *cdr(char *list)
{
  int depth=0;
  bool flag=0;    
  list = index(list, '(');
  while(list[0] != '\0'){
    printf("%d %d %c\n", depth, flag, list[0]);
    switch (list[0]){
    case '(':
      if(depth==1 && flag==1){ (list-1)[0]='('; return list=list-1; }
      depth+=1;
      break;
    case ')': depth-=1; break;
    case ' ':
      if(depth==1 && flag==1){ (list-1)[0] = '('; return list=list-1; }
      break;
    default: if(list[0] != ' ' && list[0] != '(' && depth>=1){ flag=1; } break;
    }
    list+=1;
  }
  return list;
}

char *car(char *list)
{
  int depth=0, i=0;
  bool flag=0;    
  list = index(list, '(');
  while(list[i] != '\0'){
    printf("%d %d %c\n", depth, flag, list[i]);
    switch (list[i]){
    case '(':
      if(depth==1 && flag==1){ list[0] = ' '; list[i-1]=')'; list[i] = '\0'; return list;}
      depth+=1;
      break;
    case ')': depth-=1; break;
    case ' ':
      if(depth==1 && flag==1){ list[0] = ' '; list[i-1] = ')'; list[i] = '\0'; return list;}
      break;
    default: if(list[i] != ' ' && list[i] != '(' && depth>=1){ flag=1; } break;
    }
    i+=1;
  }
  return list;
}

int main(void)
{
  char list_test[]="(((a)) ((b))(e(f)))";
  char pop[10];
  strcpy(pop, car(cdr(list_test)));
  printf("%s", pop);
  return 0;
}
