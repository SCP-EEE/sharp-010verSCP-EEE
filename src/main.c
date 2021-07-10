#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define one_code_size 2000
#define stack_size 10
#define list_size 500

#define car(list) strcpy(list, car_iter(list))
#define cdr(list) strcpy(list, cdr_iter(list))

char nil[] = "nil";

char *cdr_iter(char *list)
{
  unsigned char depth=0;
  bool flag=0;
  if(index(list, '(') == NULL){ return list; }else{ list = index(list, '('); }
  while(list[0] != '\0'){
    printf("depth:%d flag:%d %c\n", depth, flag, list[0]);
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

char *car_iter(char *list)
{
  unsigned char depth=0;
  unsigned int i=0;
  bool flag=0;
  if(index(list, '(') == NULL){ return list; }else{ list = index(list, '('); }
  while(list[i] != '\0'){
    printf("depth:%d flag:%d %c\n", depth, flag, list[i]);
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
  list[0] = ' '; *index(list, ')')=' '; return list;
}

char *cons(char *cons_list, char *car_list, char *cdr_list)
{
  char copy_list[list_size];
  strcpy(copy_list, cdr_list);
  strcpy(cons_list, "(");
  strcat(cons_list, car_list);
  strcat(cons_list, car(copy_list));
  strcat(cons_list, ")");
  return cons_list;
}

char *list(char *list)
{
  strcpy(1+list, list);
  *list = '(';
  strcat(list, ")");
  return list;
}

char *caar(char *list)
{
  car(list);
  car(list);
  return list;
}

char *cadr(char *list)
{
  cdr(list);
  car(list);
}

char eval(char *list)
{
  char *op[list_size];
  strcpy(op, list);
  car(op);

  if(!strcmp(op, "push"))
    {
    }
  else if(!strcmp(op, "pop"))
    {
    }
  else if(!strcmp(op, "exch"))
    {
    }
  else if(!strcmp(op, "match"))
    {
    }
  else if(!strcmp(op, "add"))
    {
    }
  else if(!strcmp(op, "sub"))
    {
    }
  else if(!strcmp(op, "mul"))
    {
    }
  else if(!strcmp(op, "dev"))
    {
    }
  else if(!strcmp(op, "sort"))
    {
    }
  else if(!strcmp(op, "elt"))
    {

}

int main(void)
{
  int S[stack_size];
  char E[list_size];
  char C[one_code_size];
  char D[list_size];
  char list_test[]="((a) (b (c)))";
  return 0;
}
