/*
Sample Input:
6 5
1 3 5 7 9 11
1 0 5
0 2 10
1 0 5
1 2 2
3 0 0

Sample output:
36
41
5
Invalid type code.

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

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

int construct(int *tree, int l, int r, int *arr, int i, int n){
	/*
	l, r -> range of arr that the segment is to be constructed on
	i -> current index on tree
	n -> size of arr
	*/
	int m = (l+r)/2;
	if(l >= n)return 0;
	if(l == r)return tree[i] = arr[l];
	return tree[i] = construct(tree, l, m, arr, i*2+1, n) + construct(tree, m+1, r, arr, i*2+2, n);
}

int findSum(int *tree, int l, int r, int ql, int qr, int i){
	int m = (l + r)/2;
	if(ql <= l && qr >= r)return tree[i];
	if(ql > r || qr < l)return 0;
	return findSum(tree, l, m, ql, qr, i*2 + 1) + findSum(tree, m+1, r, ql, qr, i*2 + 2);
}

void update(int *tree, int l, int r, int i, int ind, int diff){
	/*
	l, r -> range of arr covered by index  i on tree
	diff -> to be added to all nodes leading to ind
	*/
	int m = (l+r)/2;
	if(ind < l || ind > r)return;
	tree[i] += diff;
	if(l > r){
		update(tree, l, m, i*2+1, ind, diff);
		update(tree, m+1, r, i*2+2, ind, diff);
	}
}

int main(int argc, char **argv){
	int n, q, i, a, b, type, t;
	int arr[10001] = {};
	int tree[20001] = {};
	int ts;
	scanf("%d %d", &n, &q);
	rep(i, 0, n){
		scanf("%d", &arr[i]);
	}
	ts = 2*pow(2, ceil(log2(n))) - 1;
	construct(tree, 0, n-1, arr, 0, n);
	
	/*
	rep(i, 0, ts){
		printf("%d ", tree[i]);
	}
	printf("\n");
	*/

	rep(i, 0, q){
		scanf("%d %d %d", &type, &a, &b);
		if(type == 0){
			//modify
			update(tree, 0, n-1, 0, a, b - arr[a]);
			
		}
		else if(type == 1){
			//compute
			printf("%d\n", findSum(tree, 0, n-1, a, b, 0));
		}
		else printf("Invalid type code.\n");
	}
	return 0;
}

