/* Node ADT. */
typedef struct node{
	int val;
	struct node *lchild;
	struct node *rchild;
} node;

/* 
	Routine for creating a new node. This doesn't add the created
	node to the BST.
*/
node* makenode(int, node*, node*);

/* Routine for adding nodes to the BST. */
void add(node *, int);

/* In-order traversal. */
void traverseLMR(node *);

/* Pre-order traversal. */
void traverseMLR(node *);

/* Post-order traversal. */
void traverseLRM(node *);

/* Top-down level-order traversal. */
void lottopdown(node *);

/* Bottom-up level-order traversal. */
void lotbottomup(node *);

/* Level-order zigzag traversal. */
void zigzagH(node *);

/* Lowest Common Ancestor. */
node * lca(node *, node *, node *);
