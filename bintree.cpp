#include<cstdio>
#include<cstdlib>
#include<queue>
#include "bintree.h"
using namespace std;

node* makenode(int val, node* l, node* r){
	node* n = (node*)malloc(sizeof(node*));
	n->val = val;
	n->lchild = l;
	n->rchild = r;
	return n;
}

void traverseLMR(node *root){
	/* Inorder traversal of BST */
	if(!root)
		return;
	traverseLMR(root->lchild);
	printf(" %d", root->val);
	traverseLMR(root->rchild);
}
void traverseMLR(node *root){
	/* Pre-order traversal of BST */
	if(!root)
		return;
	printf(" %d", root->val);
	traverseMLR(root->lchild);
	traverseMLR(root->rchild);
}
void traverseLRM(node *root){
	/* Post-order traversal of BST */
	if(!root)
		return;
	traverseLRM(root->lchild);
	traverseLRM(root->rchild);
	printf(" %d", root->val);	
}


void _add(node* root, node *n){
	/* Adding a node to the BST at node root */
	if(!root)
		return;
	if(n->val <= root->val){
		if(root->lchild){
			_add(root->lchild, n);
		}
		else {
			root->lchild = n;
		}
	}
	else{
		if(root->rchild){
			_add(root->rchild, n);
		}
		else{
			root->rchild = n;
		}
	}
}

void add(node *root, int val){
	/* Driver function for adding a value to the BST. */
	node *n = makenode(val, NULL, NULL);
	_add(root, n);
}

void lottopdown(node *root){
	/* Level order traversal, top to bottom. */
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		queue<node*> temp;
		while(!q.empty()){
			node* tp = q.front();
			q.pop();
			printf(" %d", tp->val);
			if(tp->lchild)
				temp.push(tp->lchild);
			if(tp->rchild)
				temp.push(tp->rchild);
		}
		q = temp;
	}	
}

node* input(){
	/* Takes the input of a BST. */
	int n;
	printf("Enter number of nodes to add: ");
	scanf("%d", &n);
	if(n == 0)
		return NULL;
	node *r = NULL;	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(r)
			add(r, x);
		else r = makenode(x, NULL, NULL);
	}
	return r;
}

int main(){
	node *root = input();
	if(root){
		printf("In-order:");
		traverseLMR(root);
		printf("\nPre-order:");
		traverseMLR(root);
		printf("\nPost-order:");
		traverseLRM(root);
		printf("\nLOT Top-down:");
		lottopdown(root);
		printf("\n");
	}
	return 0;
}

