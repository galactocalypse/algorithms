/*
Sample Input:
4 2
1 2
0 3

Sample Output:
Index: Parent, Rank
0: 0, 1
1: 1, 1
2: 1, 0
3: 0, 0

*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 100001

int rank[LIM] = {};
int parent[LIM] = {};

int find(int i){
	while(i != parent[i]){
		parent[i] = parent[i = parent[i]];
	}
	return i;
}

int join(int i, int j){
	int x = find(i);
	int y = find(j);
	if(x == y)return x;
	if(rank[x] > rank[y])
		parent[y] = x;
	else if(rank[x] < rank[y])
		parent[x] = y;
	else{
		rank[x]++;
		parent[y] = x;
	}
}

int main(int argc, char **argv){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	rep(i, 0, n){
		parent[i] = i;
		rank[i] = 0;
	}
	rep(i, 0, m){
		scanf("%d %d", &a, &b);
		join(a, b);
	}
	printf("Index: Parent, Rank\n");
	rep(i, 0, n){
		printf("%d: %d, %d\n", i, parent[i], rank[i]);
	}
	return 0;
}

