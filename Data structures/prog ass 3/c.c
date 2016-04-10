#include<stdio.h>
#include<stdlib.h>

struct node{
int value;
char val;
int prc;
struct node *prev;
struct node *next;
};

struct node *mknd(char ch){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->val=ch;
temp->prev=NULL;
temp->next=NULL;
temp->prc=0;
if(ch=='+' || ch=='-')
temp->prc=1;

if(ch=='*' || ch=='/')
temp->prc=2;

if(ch=='^')
temp->prc=3;

return temp;
}

struct node* push(struct node *str,char ch){

struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->val=ch;
if(ch=='+' || ch=='-')
temp->prc=1;

if(ch=='*' || ch=='/')
temp->prc=2;
temp->prev=str;
temp->next=NULL;
str->next=temp;
str=temp;
return str;
}

struct node* pushoprnd(struct node *str,int val){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->value=val;
temp->prc=2;
temp->prev=str;
temp->next=NULL;
str->next=temp;
str=temp;
return str;

}

struct node *pop(struct node * temp){
return temp->prev;
}

void display(struct node *ptr){

if(ptr==NULL)
printf("stack is empty");
else {
while(ptr->prev!=NULL){
printf("%c %d\n",ptr->val,ptr->prc);
ptr=ptr->prev;
}
}
}

void displayoprnd(struct node *ptr){

if(ptr==NULL)
printf("stack is empty");
else {
while(ptr->prev!=NULL){
printf("%d",ptr->value);
ptr=ptr->prev;
}
}
}

int power(int a,int b){
int  ans=1;

while(b){
ans=ans*a;
b--;
}

return ans;
}



int evaluate(int a,int b,char oprtr){

if(oprtr=='+')
return a+b;

if(oprtr=='-')
return a-b;

if(oprtr=='*')
return a*b;

if(oprtr=='/')
return a/b;

if(oprtr=='^')
return power(a,b);

}

int main(){
struct node *oprnd,*oprtr;
oprnd=(struct node*)malloc(sizeof(struct node));
oprtr=(struct node*)malloc(sizeof(struct node));
//oprnd=NULL;
//oprtr=NULL;

char ch;
int value;
int p=0;

scanf("%d",&value);


 while(1)
{

//--------------------------


oprnd=pushoprnd(oprnd,value);

//--------------------------
ch=getchar();

if(ch=='#')
break;

if(p==0)
{
oprtr=push(oprtr,ch);
}
//--------------------------
if(p==1){
struct node *temp=mknd(ch);



while((temp->prc)<=(oprtr->prc) && (temp->val)!=(oprtr->val)){
//printf("hi");
int result=evaluate(oprnd->prev->value,oprnd->value,oprtr->val);
//printf("%d\n",result);
oprnd=pop(oprnd);
oprnd=pop(oprnd);
oprnd=pushoprnd(oprnd,result);
oprtr=pop(oprtr);
}


oprtr=push(oprtr,ch);

}

p=1;
scanf("%d",&value);
}


while((oprtr->prev)!=NULL){
int result =evaluate(oprnd->prev->value,oprnd->value,oprtr->val);
//printf("%d",result);
oprnd=pop(oprnd);
oprnd=pop(oprnd);
oprnd=pushoprnd(oprnd,result);
oprtr=pop(oprtr);
}

displayoprnd(oprnd);
//display(oprtr);


return 0;

}
                          

