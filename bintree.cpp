/*
	I wanted to do this entirely in C but didn't feel like
	writing the stack and queue functionalities all over again.
	Apart from the parts involving a stack/queue, the code is
	C-compatible.
*/

#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include "bintree.h"
using namespace std;

node* makenode(int val, node *l, node *r){
	/*
		Creates and returns a new node with the specified values.
	*/
	node *n = (node *)malloc(sizeof(node *));
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


void _add(node *root, node *n){
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
	/*
	You may store either the pointers to the nodes or the actual 
	values or any other associated value in queue.
	Here, I'm storing the pointers to the nodes.
	*/
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

void lotbottomup(node *root){
	stack<node*> s;
	queue<node*> q;
	/*
	You may push either the pointers to the nodes or the actual 
	values or any other associated value to the stacks and queues.
	Here, I'm pushing the pointers to the nodes. 
	*/
	q.push(root);
	while(!q.empty()){
		queue<node*> temp;
		stack<node*> ts;
		while(!q.empty()){
			node* t = q.front();
			q.pop();
			ts.push(t);
			if(t->lchild){
				temp.push(t->lchild);
			}
			if(t->rchild){
				temp.push(t->rchild);
			}
		}
		q = temp;
		while(!ts.empty()){
			/*
			The reason the elements are not directly pushed to
			the main stack s is that it would reverse the order of
			elements (left to right) at each level.
			Storing to a separate stack does cost some extra time
			and space, but preserves the left to right order.
			*/
			s.push(ts.top());
			ts.pop();
		}
	}
	while(!s.empty()){
		printf(" %d", s.top()->val);
		s.pop();
	}
}

void zigzagH(node *root){
	/*
	Horizontal zigzag traversal. (First level left to right,
	second level right to left, third left to right and so on.)

	We we simply use a stack for reversing odd numbered levels.
	*/
	queue<node*> q;
	/*
	You may push either the pointers to the nodes or the actual 
	values or any other associated value to the stacks and queues.
	Here, I'm pushing the pointers to the nodes. 
	*/
	q.push(root);
	int level = 0;
	while(!q.empty()){
		queue<node*> temp;
		stack<node*> ts;
		while(!q.empty()){
			node* t = q.front();
			q.pop();
			if(level & 1){
				ts.push(t);
			}
			else printf(" %d", t->val);
			if(t->lchild){
				temp.push(t->lchild);
			}
			if(t->rchild){
				temp.push(t->rchild);
			}
		}
		q = temp;
		if(level & 1){
			while(!ts.empty()){
				/*
				The reason the elements are not directly pushed to
				the main stack s is that it would reverse the order of
				elements (left to right) at each level.
				Storing to a separate stack does cost some extra time
				and space, but preserves the left to right order.
				*/
				printf(" %d", ts.top()->val);
				ts.pop();
			}
		}
		level++;
	}
}

node* lca(node *root, int a, int b){
	/*
	Finally something that uses the BST property!
	Starting from the root and traversing downwards towards 
	the nodes and b, the LCA is the first node with its value
	lying between a and b.
	
	This routine assumes that a and b are present in the BST.
	If they are not, the answer is based on their positions 
	had they been in the BST.
	*/
	
	if(a > b){
		return lca(root, b, a);
	}
	while(root){
		if(a <= root->val && b > root->val){
			break;
		}
		else if(a <= root->val && b <= root->val){
			root = root->lchild;
		}
		else {
			root = root->rchild;
		}
	}
	return root;
}

node * input(){
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
	int a, b;
	if(root){
		printf("In-order:");
		traverseLMR(root);
		printf("\nPre-order:");
		traverseMLR(root);
		printf("\nPost-order:");
		traverseLRM(root);
		printf("\nLOT Top-down:");
		lottopdown(root);
		printf("\nLOT Bottom-up:");
		lotbottomup(root);
		printf("\nZigzag H:");
		zigzagH(root);
		printf("\nEnter two nodes to find the LCA of:");
		scanf("%d %d", &a, &b);
		printf("LCA of %d and %d: %d\n", a, b, lca(root, a, b)->val);
	}
	return 0;
}

