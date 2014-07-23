typedef struct node{
	int val;
	struct node *lchild;
	struct node *rchild;
} node;

node* makenode(int, node*, node*);
void traverseLMR(node*);
void traverseMLR(node*);
void traverseLRM(node*);
void add(node*, int);

