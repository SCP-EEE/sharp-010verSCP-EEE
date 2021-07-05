#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define one_code_size 200
#define stack_size 10
#define list_size 50

char *cdr(char *list)
{
  unsigned char depth=0;
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
  unsigned char depth=0;
  unsigned int i=0;
  bool flag=0;    
  list = index(list, '(');
  while(list[i] != '\0'){
    printf("%d %d %c\n", depth, flag, list[i]);
    switch (list[i]){
    case '(':
      if(depth==1 && flag==1){ list[0] = ' '; /* list[i-1]=')'; */ list[i] = '\0'; return list;}
      depth+=1;
      break;
    case ')': depth-=1; break;
    case ' ':
      if(depth==1 && flag==1){ list[0] = ' '; /* list[i-1] = ')'; */ list[i] = '\0'; return list;}
      break;
    default: if(list[i] != ' ' && list[i] != '(' && depth>=1){ flag=1; } break;
    }
    i+=1;
  }
  return list;
}

int main(void)
{
  char list_val[list_size][30];
  char *list[list_size];
  int S[stack_size];
  char *E[list_size];
  char *C[one_code_size];
  char *D[list_size];
  char list_test[]="((a) (b (c)))";
  strcpy(list_val[0], list_test);
  car(list_val[0]);
  list[0] = list_val[0];
  strcpy(list_val[1], list_test);
  cdr(list_val[1]);
  list[1] = list_val[1];
  printf("%s %s", list[0], list[1]);
  return 0;
}
