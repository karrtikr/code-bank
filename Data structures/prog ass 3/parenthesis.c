#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
  struct node *next;
  char *data;
} node;

node* make_node(char* a,int i,int j){
  node *s;
  s = (node*)malloc(sizeof(node));
  s->data = (char*)malloc((j-i)*sizeof(char));
  int k;
  for(k=0;k<j-i;k++){
    *((s->data)+k) = a[k+i];
  }
  s->next = NULL;
  return s;
}

void push(node** head, char* p, int i, int j){
  node *tmp = make_node(p,i,j);
  if ((*head) == NULL){
    tmp->next = NULL;
    *head = tmp;
  }
  else {
    tmp->next = *head;
    *head = tmp;
  }
}

char *pop(node **head){
  if (*head == NULL) return NULL;
  else {
    node* tmp = *head;
    *head = tmp->next;
    return tmp->data;
  }
}

char* top(node* x){
  return x->data;
}

int ipriority(char c){
  switch(c) {
    case('$'):
      return 0;
    case('^'):
      return 5;
    case('+'):
      return 1;
    case('-'):
      return 1;
    case('/'):
      return 3;
    case('*'):
      return 3;
    case('#'):
      return -1;
    case('('):
      return 0;
    default: return 0;
  }
}

int opriority(char c){
  switch(c) {
    case('$'):
      return 0;
    case('^'):
      return 6;
    case('+'):
      return 1;
    case('-'):
      return 2;
    case('/'):
      return 4;
    case('*'):
      return 3;
    case('#'):
      return -1;
    case('('):
      return 7;
    default: return 0;
  }
}

int execute(int a, int b, char c){
  switch(c) {
    case('+'):
      return (a+b);
    case('-'):
      return (a-b);
    case('*'):
      return (a*b);
    case('/'):
      return (a)/b;
    case('^'):
      return (int)(pow((double)a,(double)b));
    default: return 0;
  }
}

int main(){
  char a[1000];
  scanf("%s",a);
  if(*a=='#')
    return 0;
  char b = '$',c;
  node* num = NULL;
  node* op = NULL;
  push(&op, &b, 0, 1);
  char* p = a;
  int k = 0,l;
  while (*p!='#' ||*top(op) != '$'){
    if(*p>=48 && *p<=57){
      while(*(p+k)>=48 && *(p+k)<=57) k++;
      push(&num,p,0,k);
      p = p+k;
      k = 0;
    }
    else if(*p=='#'){
      while(*top(op)!='$'){
        char c = *(pop(&op));
        int n = atoi(pop(&num));
        int m = atoi(pop(&num));
        l = execute(m,n,c);
        char d[100];
        sprintf(d,"%d",l);
        push(&num,d,0,strlen(d));
      }
    }
    else if(*p==')'){
      while(*top(op)!='('){
        c = *(pop(&op));
        int n = atoi(pop(&num));
        int m = atoi(pop(&num));
        l = execute(m,n,c);
        char d[100];
        sprintf(d,"%d",l);
        push(&num,d,0,strlen(d));
      }
      c=*(pop(&op));
      p=p+1;
    }
    else{
      while(ipriority(*top(op))>=opriority(*p)){
        c = *(pop(&op));
        int n = atoi(pop(&num));
        int m = atoi(pop(&num));
        l = execute(m,n,c);
        char d[100];
        sprintf(d,"%d",l);
        push(&num,d,0,strlen(d));
      }
      push(&op, p, 0, 1);
      p = p+1;
    }
  }
  int ans = atoi(pop(&num));
  printf ("%d\n",ans);
  return 0;
}
