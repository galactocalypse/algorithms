/*
Sample Input:
9
10 22 9 33 21 50 41 60 80
Sample Output:
Length of LIS: 6
80	60	41	33	22	10

*/

#include<stdio.h>
int arr[1001] = {};
int len[1001] = {};
int parent[1001] = {};
int n;
int lis(){
	int max, i, j;
	for(i = 0; i < n; i++){
		len[i] = 1;
		parent[i] = i;
	}
	for(i = 1; i < n; i++){
		for(j = i-1; j >= 0; j--){
			if(arr[j] < arr[i] && len[j] + 1 > len[i]){
				len[i] = len[j] + 1;
				parent[i] = j;
			}
		}
	}
	max = 0;
	for(i = 1; i < n; i++){
		if(len[i] > len[max])
			max = i;
	}
	
	return max;
}
int main(){
	int i, max;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	max = lis();
	printf("Length of LIS: %d\n", len[max]);
	while(max != parent[max]){
		printf("%d\t", arr[max]);
		max = parent[max];
	}
	printf("%d\n", arr[max]);
	return 0;
}
