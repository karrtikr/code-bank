#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node* down;
} node;

node* newnode(char x){
	node* p=(node*)malloc(sizeof(node)*1);
	p->data=x;
	p->down=NULL;
	return p;
}

node* Push(char x,node* S){
	node* n=newnode(x);
	n->down=S;
	S=n;
	return S;
}

node* Pop(node* S){
	node* temp;
	temp=S->down;
	free(S);
	S=temp;
	return S;
}

int IsEmpty(node* S){
	if(S==NULL){
		return 1;
	}
	else
		return 0;
}

int Top(node* S){
	return S->data;
}

int main(){
	node* S=NULL;
	char x;int i,n;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf(" %c",&x);
		if(x=='\n'||x==' ')
		{
			i=i-1;
			continue;
		}
		S=Push(x,S);
	}

	printf("\nIs Stack Empty? %d\n",IsEmpty(S));
	for(i=0;i<n;i++){
		printf("%c ",Top(S));
		S=Pop(S);
	}
	return 0;
}