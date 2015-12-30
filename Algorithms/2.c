#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int max(int x,int y)
{
	if(y>x)
		return y;
	else
		return x;
}

int height(node* root){
	if(root==NULL)
		return -1;
	return max(height(root->left),height(root->right))+1;
}

node* leftrotate(node* p){
	if(p==NULL||p->right==NULL)
		return p;
	node* t;
	t=p->right;
	p->right=t->left;
	t->left=p;
	return t;
}

node* rightrotate(node* p){
	if(p==NULL||p->left==NULL)
		return p;
	node* t;
	t=p->left;
	p->left=t->right;
	t->right=p;
	return t;
}

node* makeskew(node* root){
	node* r;
	while(root->left!=NULL){
		root=rightrotate(root);
	}
	r=root;
	while(root->right!=NULL){
		while(root->right->left!=NULL){
			root->right=rightrotate(root->right);
		}
		root=root->right;
	}
	return r;
}
int div2(int m){
	while(m>=1){
		if(m%2==1&& m!=1)
			return 0;
		m=m/2;
	}
	return 1;
}

int abs (int x) {
  if (x < 0) return -x;
  return x;
}

int signum (int x) {
  if (x < 0) return -1;
  if (x > 0) return 1;
  return 0;
}

int add (int x, int y) {
  for (int i = 0; i < abs(y); ++i) {
    if (y > 0) ++x;
    else --x;
  }
  return x;
}

int mult (int x, int y) {
  int sign = signum(x) * signum(y);
  x = abs(x);
  y = abs(y);
  int res = 0;
  for (int i = 0; i < y; ++i) {
    res = add(res, x);
  }
  return sign * res;
}

int pow1(int x, int y) {
  if (y < 0) return 0;
  int res = 1;
  for (int i = 0; i < y; ++i) {
    res = mult(res, x);
  }
  return res;
}

int floor1(int n){
	int floor=0;
	while(n>=1)
	{
		n=n/2;
		floor=floor+1;
	}
	return floor-1;
}

node* rebalance(node* root,int n){
	int l;int c,i;node* r;
	l=floor1(n+1);
	if(div2(n+1)==1)
		c=pow1(2,l);
	else
		c=n+1-pow1(2,l);
	for(i=0;i<c;i++){
		root=leftrotate(root);
	}
	r=root;
	root=root->right;
	if(root!=NULL){
		while(root->right!=NULL){
			for(i=0;i<c;i++){
				root->right=leftrotate(root->right);
			}
			root=root->right->right;
		}
		root=r;
		n=n-c;
		while(n>1){
			n=n/2;
			for(i=0;i<n;i++){
				root=leftrotate(root);
			}
			r=root;
			root=root->right;
			while(root->right!=NULL){
				for(i=0;i<n;i++){
					root->right=leftrotate(root->right);
				}
				root=root->right->right;
			}
		}
	}
	
	return r;
}

int main(){
	node* root=NULL;	
	int n,i,key;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&key);
		root=insert(root,key);
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	printf("%d\n",height(root));
	root=makeskew(root);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");printf("\n");printf("\n");printf("\n");
	root=rebalance(root,n);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	return 0;
}