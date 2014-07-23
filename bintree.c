#include<stdio.h>
#include<malloc.h>
#include "bintree.h"

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

int main(){
	node *root = makenode(50, NULL, NULL);
	add(root, 25);
	add(root, 75);
	
	printf("In-order:");
	traverseLMR(root);
	printf("\nPre-order:");
	traverseMLR(root);
	printf("\nPost-order:");
	traverseLRM(root);
	printf("\n");
	return 0;
}

