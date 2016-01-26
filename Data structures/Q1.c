#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data,i,j;
	struct node* right;	//in case of column-head and value nodes it points towards the next non-zero node towards right
	struct node* down;	//in case of row-head and value nodes it points towards the next non-zero node towards down
} node;

node* newnode(int val,int x,int y){		//returns the pointer to the new node to be inserted
	node* p=(node*)malloc(sizeof(node)*1);
	p->data=val;
	p->i=x;
	p->j=y;
	p->right=NULL; p->down=NULL;
	return p;
}

void insert(node* p,node* q,int x,int y,int val){
	int k;
	node* temp; node* n;
	n=newnode(val,x,y);
	for(k=1;k<y;k++){
		p=p->right;				//traversing rightwards to the index to be inserted
	}
	temp=p->down;
	if(temp==NULL||temp->i>=x)	//taking care of the initial conditions
		p->down=n;
	p=temp;
	while(p!=NULL && p->i<x){
		temp=p->down;
		if(temp==NULL||temp->i>=x)	//as just before finishing the loop we need to point towards the newnode
			p->down=n;				//linking the pointers appropiately
		p=temp;
	}
	n->down=p;
	for(k=1;k<x;k++){
		q=q->down;				//traversing downwards to the index to be inserted
	}
	temp=q->right;
	if(temp==NULL||temp->j>=y)
		q->right=n;
	q=temp;
	while(q!=NULL && q->j<y){
		temp=q->right;
		if(temp==NULL||temp->j>=y)	//as just before finishing the loop we need to point towards the newnode
			q->right=n;				//linking the pointers appropiately
		q=temp;
	}
	n->right=q;
}

int value(node* q,int x,int y){		//returns the value stored at index (i,j)
	int k;
	for(k=1;k<x;k++){
		q=q->down;				//traversing downwards to the index to be inserted
	}
	q=q->right;
	while(q!=NULL && q->j<=y){
		if(q->j==y)
			return q->data;
		q=q->right;
	}
	return 0;	//it means either q==NULL or q->j > y, that means the search fails and value is 0
}

int main(){
	node* P1=newnode(0,0,1);	//row-head nodes of 1st matrix
	node* Q1=newnode(0,1,0);	//column-head nodes of 2nd matrix
	node* P2=newnode(0,0,1);	//row-head nodes of 1st matrix
	node* Q2=newnode(0,1,0);	//column-head nodes of 2nd matrix
	int i,j,k,l,n,x,y,val,sum;
	scanf("%d",&n);
	node* p=P1; node* q=Q1;
	for(k=1;k<n;k++){			//constructing the head nodes for matrix 1
		p->right=newnode(0,0,k+1);
		q->down=newnode(0,k+1,0);
		p=p->right;
		q=q->down;
	}
	p=P2; q=Q2;
	for(k=1;k<n;k++){			//constructing the head nodes for matrix 2
		p->right=newnode(0,0,k+1);
		q->down=newnode(0,k+1,0);
		p=p->right;
		q=q->down;
	}
	scanf("%d",&l);				//reading the matrix number
	while(l!=0){
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&val);
		if(l==1)				//passing the correct pointers
			insert(P1,Q1,x,y,val);
		else	//l==2
			insert(P2,Q2,x,y,val);
		scanf("%d",&l);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			sum=0;
			for(k=1;k<=n;k++){
				sum=sum+value(Q1,i,k)*value(Q2,k,j);
			}
			if(sum!=0)
				printf("%d %d %d\n",i,j,sum);	//multiplied and printed appropiately
		}
	}

	return 0;
}