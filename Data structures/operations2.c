#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int x = 1;    //initial values of our variables
int y = 1;

typedef struct node {
  struct node *next;
  char *data;
} node;

node* make_node(char* a,int i,int j){ //it returns a pointer to the node
  node *s;               //The data field of the node points to a string sliced from array a from a[i] to a[j-1]
  s = (node*)malloc(sizeof(node));
  s->data = (char*)malloc((j-i)*sizeof(char)); //data part is meant to hold integers of length (j-i)
  int k;
  for(k=0;k<j-i;k++){
    *((s->data)+k) = a[k+i];  //copying the characters from the array
  }
  s->next = NULL;
  return s;
}

void push(node** head, char* p, int i, int j){ //pushes the string from p[i] to p[j-1] into the stack pointed by (*head)
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

char *pop(node **head){ //deletes the top node of the stack and returns the data field
  if (*head == NULL) return NULL;
  else {
    char* temp;
    node* tmp = *head;
    *head = tmp->next;
    temp=tmp->data;
    return temp;
  }
}

int ipriority(char c){
  if (c=='$') return -1;
  if (c=='^') return 3;
  else if (c=='+' || c=='-') return 1;
  else if(c == '*' || c=='/') return 2;
  else return 0;        //carries the case when c is either '=' or '(', same priorities are required
}

int opriority(char c){
  if (c=='#') return -1;    //inside priority is not required for '#', priority should be least
  else if (c=='+' || c=='-') return 1;
  else if (c=='*' || c=='/') return 2;
  else if (c=='^') return 4;
  else return 5;       //carries the case when c is either '=' or '('
}

int execute(char *a, char *b, char c){
  int n,m,s;
  char k = *a;          //creating duplicates
  char l = *b;
  if (k == 'x') n=x;    //replacing symbol 'x' in numbers stack as its actual value
  else if (k=='y') n=y; //replacing symbol 'y' in numbers stack as its actual value
  else n = atoi(a);     //converting string to integer in normal cases
  
  if(l=='x') m = x; 
  else if (l=='y') m=y;
  else m=atoi(b);

  switch(c) {
  case('+'):
    s=(n+m); break;
  case('-'):
    s=(n-m); break;
  case('*'):
    s=(n*m); break;
  case('/'):
    s=n/m; break;
  case('^'):
    s=(int)(pow((double)n,(double)m)); break;
  case('='):
    if (*a =='x') x=m;  //updating values of x and y
    else y=m;
    s=m;           //executing operator '='
    break;
  default:s=0;
  }
  return s;
}

int main(){
  char a[100],c,d[100];
  scanf("%s",a);
  char b = '$';
  node* num = NULL;
  node* op = NULL;
  push(&op, &b, 0, 1);    //pushing '$' into stack
  char* p = a;char* m;char* n;
  int k = 0,l,size;
  while (*p!='#' || *(op->data) != '$'){
    if((*p>=48 && *p<=57)|| *p=='x' || *p=='y'){    //if next character is a number
      while((*(p+k)>=48 && *(p+k)<=57) || *(p+k)=='x' || *(p+k)=='y') k++;  //length of the number
      push(&num,p,0,k);
      p = p+k;    //updating the next token
      k = 0;
    }
    else{
      if(*p == ')'){     //if next token is ')'
	       while(*(op->data)!='('){
          n = pop(&num);
          m = pop(&num);
          c = *(pop(&op));
          l = execute(m,n,c);   //feeding the correct values
          size=sprintf(d,"%d",l);
          push(&num,d,0,size); //converting the integer into string and pushing into stack
	       }
	       pop(&op);
	       p = p+1;                  //updating the next token
      }
      else if(opriority(*p)>ipriority(*(op->data))){
	       push(&op, p, 0, 1);       //pushing operator into stack in such case
	       p = p+1;
      }
      else{
	       n = pop(&num);
         m = pop(&num);
	       c = *(pop(&op));
	       l = execute(m,n,c);   //feeding the correct values
	       size=sprintf(d,"%d",l);
	       push(&num,d,0,size); //converting the integer into string and pushing into stack
      }
    }
  }
  int ans = atoi(pop(&num));     //converting number string into integer
  printf ("%d\n",x);
  printf("%d\n",y);
  printf ("%d\n",ans);
  return 0;
}
