#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} node;

node* newnode(int key){
	node* p=(node*)malloc(sizeof(node)*1);
	p->data=key;
	return p;
}

node* insert(node* root,int key){
	if(root==NULL){
		root=newnode(key);
		return root;
	}
	if(root->data>key)
		root->left=insert(root->left,key);
	else if(root->data<key){
		root->right=insert(root->right,key);
	}
	else
		return root;
	return root;
}

void preorder(node* root){
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int max(node* root){
	if(root==NULL)
		return -1000000;
	while((root->right)!=NULL){
		root=root->right;
	}
	return root->data;
}

node* search1(float x,node* root){
	if(root==NULL)
		return NULL;
	if(root->data>x){
		if(x>max(root->left)){
			return root;
		}
		else
			return search1(x,root->left);
	}
	else if(root->data<x){

		return search1(x,root->right);
	}
	else
		return root;
}

node* lca(int p,int q,node* root){
	if(root==NULL)
		return NULL;
	if(root->data>p && root->data>q)
		return lca(p,q,root->left);
	else if(root->data<p && root->data<q)
		return lca(p,q,root->right);
	else
		return root;
}

// node* search1(float x,node* root,node* temp,node* p,int d){
// 	if(root==NULL){
// 		if((p->data)-x>0)
// 			return p;
// 		else
// 			return temp;
// 	}
// 	if(root->data>x){
// 		return search1(x,root->left,temp,root,d);
// 		d=0;
// 	}
// 	else if(root->data<x){
// 		if(d==0)
// 			temp=p;
// 		return search1(x,root->right,temp,root,d);
// 		d=1;
// 	}
// 	else
// 		return root;
// }

void print(node* lca,int x,int y){
	if(lca==NULL)
		return;
	print(lca->left,x,y);
	if(lca->data>=x&&lca->data<=y)
		printf("%d ",lca->data);
	print(lca->right,x,y);
}

int main(){
	node* root=NULL;
	node* r1;
	node* r2;
	int n,i,key;
	float x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&key);
		root=insert(root,key);
	}
	scanf("%f",&x);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	r1=search1(x,root);
	r2=lca(r1->data,18,root); 	
	printf("%d\n",r2->data);
	printf("Range is: ");
	print(r2,r1->data,18);
	printf("\n");
	return 0;
}