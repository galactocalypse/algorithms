/*
	Sample input:
	4 5
	0 1 2
	1 2 3
	2 3 4
	3 0 3
	3 1 1
	
	Sample output:
	1 3 1
	0 1 2
	1 2 3

*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 1001

typedef struct edge {
	int s;
	int d;
	int w;
} edge;

int adj[LIM][LIM] = {};
edge e[LIM];
int eds[LIM] = {};

int parent[LIM] = {};
int rank[LIM] = {};
int n, m;



int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int cmp_edge(const void *a, const void *b){
	return (*(edge*)a).w - (*(edge*)b).w;
}

void printarr(int *arr, int n){
	int i;
	rep(i, 0, n){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int find(int a){ // for disjoint set
	while(a !=parent[a]){
		int p = parent[a];
		parent[a] = parent[p];
		a = p;
	}
	return parent[a];
}

int join(int a, int b){ // for disjoint set
	int pa = find(a);
	int pb = find(b);
	if(pa == pb){
		return pa;
	}
	else if(rank[pa] > rank[pb]){
		return (parent[pb] = pa);
	}
	else if(rank[pa] < rank[pb]){
		return (parent[pa] = pb);
	}
	else{
		rank[pa]++;
		return (parent[pb] = pa);
	}
}

int main(int argc, char **argv){
	int i, s, d, w;
	scanf("%d %d", &n, &m);
	
	/* initializing disjoint set arrays*/
	rep(i, 0, n){
		parent[i] = i;
		rank[i] = 1;
	}
	
	rep(i, 0, m){
		scanf("%d %d %d", &s, &d, &w);
		e[i].s = s;
		e[i].d = d;
		e[i].w = w;
	}

	qsort(e, m, sizeof(edge), cmp_edge);

	rep(i, 0, m){
		if(find(e[i].s) != find(e[i].d)){ // if a cycle isn't formed
			join(e[i].s, e[i].d);
			eds[i] = 1;
		}
	}
	
	rep(i, 0, m){
		if(eds[i] == 1)// only edges in the MST are printed
			printf("%d %d %d\n", e[i].s, e[i].d, e[i].w);
	}
	return 0;
}

