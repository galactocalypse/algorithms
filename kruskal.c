/*
	Yet to be debugged.
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


int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int cmp_edge(const void *a, const void *b){
	return ((edge*)a)->w - ((edge*)b)->w;
}

void printarr(int *arr, int n){
	int i;
	rep(i, 0, n){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



int main(int argc, char **argv){
	int n, m, i, j, s, d, w, temp;
	int adj[LIM][LIM] = {};
	edge* e[LIM];
	scanf("%d %d", &n, &m);
	rep(i, 0, m){
		scanf("%d %d %d", &s, &d, &w);
		if(s > d){
			temp = s;
			s = d;
			d = temp;
		}
		e[i] = (edge*)malloc(sizeof(edge));
		e[i]->s = s;
		e[i]->d = d;
		e[i]->w = w;
	}
	qsort(e, m, sizeof(edge), cmp_edge);
	rep(i, 0, m){
		printf("%d %d %d\n", e[i]->s, e[i]->d, e[i]->w);
	}
	return 0;
}

