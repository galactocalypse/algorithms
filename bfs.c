/*
	Intended for dense graphs.
	
	Sample Input:
	10 9
	0 1
	1 2
	1 3
	1 4
	2 5
	3 6
	5 7
	9 8
	7 9


	Sample Output:
	Path: 0->1->2->3->4->5->6->7->9->8

*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 1001

int visited[LIM] = {};
int queue[LIM] = {};
int con[LIM][LIM] = {};
int n, m;
int path[LIM] = {};
int ptr;
int qf, qb;

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void bfs(int ind){
	int j;
	if (ind >= n || visited[ind]) return; // came here by mistake
	
	ptr = qf = qb = 0;
	queue[qb++] = ind;
	rep(j, 0, n)
		visited[j] = 0;
	
	while(qf != qb){ // queue isn't empty
		
		/* process current node */
		path[ptr++] = queue[qf];
		
		/* mark as processed */
		visited[queue[qf]] = 1;
		
		/* add neighbours */
		rep(j, 0, n){
			if(con[queue[qf]][j] && !visited[j])
				queue[qb++] = j;
		}
		
		/* pop out processed node */
		qf++;
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
		scanf("%d %d", &a, &b);
		con[a][b] = 1;
	}
	
	bfs(0);
	
	printf("Path: ");
	rep(i, 0, ptr){
		printf("%d", path[i]);
		if(i < ptr-1)
			printf("->");
	}
	printf("\n");
	
	return 0;
}

