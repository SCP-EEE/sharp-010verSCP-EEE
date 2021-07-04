#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define one_code_size 200
#define stack_size 10
#define list_size 50
#define val_size 30

char nil[] = "nil";

char *cdr(char *list)
{
  unsigned char depth=0;
  bool flag=0;    
  list = index(list, '(');
  while(list[0] != '\0'){
    #ifndef DEBUG
    printf("depth:%d flag:%d %c\n", depth, flag, list[0]);
    #endif
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
    #ifndef DEBUG
    printf("depth:%d flag:%d %c\n", depth, flag, list[i]);
    #endif
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

void list_up(char *check_list, char *list, char **list_val){
  unsigned char depth=0;
  unsigned int list_index=0, n=0, m=0, chklist_index=0;
  bool flag=0;
  list = index(list, '(');
  while(check_list[chklist_index] != '\0'){
    #ifndef DEBUG
    printf("depth:%d flag:%d %c\n", depth, flag, check_list[chklist_index]);
    #endif
    switch (check_list[chklist_index]){
    case '(':
      if(depth==1 && flag==1){  }
      list[list_index] = list[2+list_index];
      list[1+list_index] = *nil;
      depth+=1;
      break;
    case ')': depth-=1; break;
    case ' ':
      if(depth==1 && flag==1){  }
      break;
    default: if(check_list[chklist_index] != ' ' && check_list[chklist_index] != '('){ list_val[m==val_size ? n++ : n][m==val_size ? m=0 : m++] = check_list[chklist_index]; list[strcmp(list[list_index], "nil") ? 2+list_index : list_index] = list_val[m-1]; } if(depth>=1){ flag=1; } break;
    }
    list_index+=1;
  }
}

int main(void)
{
  char list_val[list_size][val_size];
  char *list[list_size];
  int S[stack_size];
  char *E[list_size];
  char *C[one_code_size];
  char *D[list_size];
  char list_test[]="((a) (b (c)))";
  return 0;
}
