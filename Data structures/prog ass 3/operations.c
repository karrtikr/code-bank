#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
  struct node *next;
  char *data;
} node;

node* make_node(char* a,int i,int j){
  //printf ("Making node %s i = %d j = %d\n",a,i,j);
  node *s;
  s = (node*)malloc(sizeof(node));
  s->data = (char*)malloc((j-i)*sizeof(char));
  //printf("I am sanjay.");
  //printf("executing loop in make_node\n");
  //printf("I am sanjay.\n");
  //printf("size of string = %d\n",n); 
  int k;
  for(k=0;k<j-i;k++){
    //printf("%c\n",a[i+k]);
    *((s->data)+k) = a[k+i];
  }
  //printf("after make_node = %s\n", s->data);
  //printf("Loop Ended.\n");
  s->next = NULL;
  return s;
}

void push(node** head, char* p, int i, int j){
  //printf("pushing node %s\n",p);
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
  //printf ("popping \n");
  if (*head == NULL) return NULL;
  else {
    node* tmp = *head;
    //printf("seg fault here.\n");
    *head = tmp->next;
    //printf("seg fault here.\n");
    return tmp->data;
  }
}

int priority(char c){
  //printf ("Giving priority of %c\n",c);
  if (c=='$') return 0;
  if (c=='^') return 3;
  else if (c=='+' || c=='-') return 1;
  else if(c == '#') return -1;
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
  char a[500];
  scanf("%s",a);
  char b = '$';
  node* num = NULL;
  node* op = NULL;
  push(&op, &b, 0, 1);
  char* p = a;
  int k = 0;
  while (*p!='#' || *(op->data) != '$'){
    if(*p>=48 && *p<=57){
      while(*(p+k)>=48 && *(p+k)<=57) k++;
      push(&num,p,0,k);
      //printf("num->data = %s\n",(num->data)); 
      p = p+k;
      k = 0;
    }
    else{
      if(priority(*p)>priority(*(op->data))){
	     push(&op, p, 0, 1);
	     p = p+1;
      }
      else{
	     int n = atoi(pop(&num));
	//printf ("n = %d\n", n);
	//printf("num->data = %d\n", *(num->data));
	     int m = atoi(pop(&num));
	//printf("m = %d\n",m);
	     char c = *(pop(&op));
	//char t = *(pop(&op));
	     int l = execute(m,n,c);
	//printf ("%d %c %d = %d",n,c,m,l);
	     char d[100];
	     sprintf(d,"%d",l);
	//printf("%s", d);
	     push(&num,d,0,strlen(d));
	//printf("After sprintf num->data = %s",num->data);
      }
    }
  }
  int ans = atoi(pop(&num));
  printf ("ans = %d",ans);
  return 0;
}
