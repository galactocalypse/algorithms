/*
This is the O(logN) searching version.
*/
#include<stdio.h>
#define MAX 1001
int arr[MAX] = {};
int c[MAX] = {};
int parent[1001] = {};
int n;

int binsearch(int l, int h, int s){
	int m = (h+l)/2;
	if(h < l)return -1;
	else if(l == h){
		if(arr[c[m]] > s)
			return m;
		else return -1;
	}
	else{
		if(arr[c[m]] < s)
			return binsearch(m+1, h, s);
		else return binsearch(l, m, s);
	}
	return -1;
}

int lis(){
	int max, i, j, l = 1, k;
	for(i = 0; i < n; i++){
		parent[i] = i;
	}
	c[1] = 0;
	for(i = 1; i < n; i++){
		j = binsearch(1, l, arr[i]);
		if(j == -1){
			c[++l] = i;
			parent[i] = c[l - 1];
		}
		else{
			if(parent[c[j]] != c[j])
				parent[i] = parent[c[j]];
			c[j] = i;
		}
	}
	return l;
}

int main(void){
	int i, max;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	max = lis();
	printf("Length of LIS: %d\n", max);
	i = c[max];
	printf("Sequence in reverse: \n");
	do{
		printf("%d\t", arr[i]);
		i = parent[i];
	}while(parent[i] != i);	
	printf("%d\n", arr[i]);
	return 0;
}

