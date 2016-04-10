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

int priority(char c){
  if (c=='$') return 0;
  if (c=='^') return 3;
  else if (c=='+' || c=='-') return 1;
  else if(c == '#') return -1;
  else return 2;
}

int opriority(char c){
  if (c=='$') return 0;
  if (c=='^') return 3;
  else if (c=='+' || c=='-') return 1;
  else if(c == '#') return -1;
  else if(c=='(') return 4;
  else return 2;
}

int execute(int a, int b, char c){
//printf ("executing %d %c %d",a,c,b);
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
  }
}

int main(){
  char a[100];
  scanf("%s",a);
  char b = '$';
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
    else{
      while(priority(*top(op))>=priority(*p)){
        char c = *(pop(&op));
        int n = atoi(pop(&num));
        int m = atoi(pop(&num));
        int l = execute(m,n,c);
        char d[100];
        sprintf(d,"%d",l);
        push(&num,d,0,strlen(d));
      }
      push(&op, p, 0, 1);
      p = p+1;
    }
  }
  int ans = atoi(pop(&num));
  printf ("ans = %d\n",ans);
  return 0;
}
