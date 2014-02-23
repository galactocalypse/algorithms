/*
	The easiest all pairs-shortest path algorithm, with a complexity of O(N^3), where N is the number of nodes in the graph.
	
	Sample Input:
	4 4
	0 1 5
	0 3 10
	1 2 3
	2 3 1

	Sample Output:
	0	5	8	9
	INF	0	3	4
	INF	INF	0	1
	INF	INF	INF	0
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define INF 99999999
#define LIM 1001
int n;
int e[LIM][LIM] = {};

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void printarr(int *arr, int n){
	int i;
	rep(i, 0, n){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void floyd_warshall(){
	int i, j, k;
	rep(i, 0, n){
		rep(j, 0, n){
			rep(k, 0, n){
				e[i][j] = min(e[i][j], e[i][k]+e[k][j]);
			}
		}
	}
}

int main(int argc, char **argv){
	int m, i, j, s, d, c;
	scanf("%d %d", &n, &m);
	rep(i, 0, n){
		rep(j, 0, n){
			if(i != j)
				e[i][j] = INF;
			else e[i][j] = 0;	
		}
	}

	rep(i, 0, m){
		scanf("%d %d %d", &s, &d, &c);
		e[s][d] = c;
	}
	rep(i, 0, n){
		printarr(e[i], n);
	}
	floyd_warshall();
	rep(i, 0, n){
		rep(j, 0, n){
			if(e[i][j] == INF){
				printf("INF\t");
			}
			else printf("%d\t", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}

