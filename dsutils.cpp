#include<bits/stdc++.h>
using namespace std;
//for SLLs
struct SLLNode{
	SLLNode *next;
	int data;
};

//for DLLs and BSTs
struct BSTNode{
	BSTNode *left;
	BSTNode *right;
	int data;
};

SLLNode* createSLLNode(int val){
	SLLNode *nd = (SLLNode*)malloc(sizeof(SLLNode));
	nd->data = val;
	nd->next = NULL;
	return nd;
}

BSTNode* createBSTNode(int val){
	BSTNode *nd = (BSTNode*)malloc(sizeof(BSTNode));
	nd->data = val;
	nd->left = nd->right = NULL;
	return nd;
}

void appendToSLL(SLLNode *root, SLLNode *nd){
	if (root != NULL && nd != NULL) {
		while (root->next) {
			root = root->next;
		}
		root->next = nd;
	}
}

void insert(BSTNode *root, BSTNode *nd){
	if (root != NULL && nd != NULL) {
		if (nd->data < root->data) {
			if (root->left == NULL) {
				root->left = nd;
			}
			else {
				insert(root->left, nd);
			}
		}
		else {
			if (root->right == NULL) {
				root->right = nd;
			}
			else {
				insert(root->right, nd);
			}
		}
	}
}

SLLNode* createSLL(int s, int e){
	SLLNode *list = NULL;
	for (int i = e; i >= s; i--) {
		SLLNode *nd = createSLLNode(i);
		if (list == NULL) {
			list = nd;
		}
		else {
			appendToSLL(nd, list);
			list = nd;
		}
	}
	return list;
}

BSTNode* createBST(int s, int e){
	if (s <= e){
		int m = s + (e-s)/2;
		BSTNode *left = createBST(s, m-1);
		BSTNode *right = createBST(m+1, e);
		BSTNode *root = createBSTNode(m);
		root->left = left;
		root->right = right;
		return root;
	}
	else {
		return NULL;
	}
}

void inorder(BSTNode *root){
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void printSLL(SLLNode *root){
	while (root != NULL) {
		cout << root->data << " ";
		root = root->next;
	}
	cout << endl;
}

int main(void){
	SLLNode *sll = createSLL(1, 10);
	printSLL(sll);

	BSTNode *bst = createBST(1, 10);
	inorder(bst);
	cout << endl;
	return 0;
}

