/*
	Works only for dense graphs. Will upload the adjacency list version soon.
	This implementation is for directed graphs. It can be modified for undirected graphs by making conn symmetric.

	Sample Input:
	5 5
	0 2
	2 1
	1 0
	2 4
	4 3

	Sample Output:
	Path: 0->2->1->4->3
	
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 1001

int path[LIM] = {};
int con[LIM][LIM] = {};
int visited[LIM] = {};
int n; // number of nodes
int m; // number of edges
int ptr; // path pointer

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void dfs(int ind){
	/*
		The iterative version is a little tricky and beyond my scope right now.
		Some iterative depth-deepening stuff that I don't get at the moment.
	*/
	int i;
	
	if (ind >= n) return; // in case you came here by mistake
	
	/* do stuff with the node */
	path[ptr++] = ind;

	/* mark this node as processed */
	visited[ind] = 1;
	
	/* process the unprocessed neighbours */
	rep(i, 0, n){
		if(con[ind][i] && !visited[i])
			dfs(i);
	}
}

void printarr(int *arr, int n){
	int i;
	rep(i, 0, n){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv){
	int i, a, b;
	scanf("%d %d", &n, &m);
	rep(i, 0, m){
		scanf("%d %d", &a, &b); // edge from a to b
		con[a][b] = 1;
	}
	ptr = 0;
	dfs(0); // Starting from node 0. Can start from any node.

	printf("Path: ");
	rep(i, 0, ptr){
		printf("%d", path[i]);
		if(i < ptr-1)
			printf("->");
	}
	printf("\n");
	return 0;
}

