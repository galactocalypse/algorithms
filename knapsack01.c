/*

Sample input:
5 8
4 3 5 6 2
9 8 10 9 3
Sample output:
Max value: 18

*/
#include<stdio.h>
#define max(a, b) ((a) > (b)?(a):(b))
#define ILIM 101
#define CLIM 1001
int n, w;
int dp[ILIM][CLIM];
int arr[ILIM];
int val[ILIM];
int sel[ILIM];

int knapsack01(){
	int i, j;
	for(i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(i = 0; i <= w; i++)
		dp[0][i] = 0;
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= w; j++){
			if(j >= arr[i])
				dp[i][j] = max(val[i] + dp[i-1][j-arr[i]], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

void findinc(){
	//find included items
}

int main(void){
	int i, j;
	scanf("%d %d", &n, &w);
	for(i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	for(i = 1; i <= n; i++){
		scanf("%d", &val[i]);
	}
	printf("Max value: %d\n", knapsack01());
	/*
	findinc();
	for(i = 0; i <= n; i++){
		for(j = 0; j <= w; j++){
			printf("%d\t", dp[i][j]);
		}
		printf("\n");
	}
	printf("Selected items: ");
	for(i = 1; i <= n; i++){
		if(sel[i])printf("%d(%d) ", arr[i], val[i]);
	}
	printf("\n");
	*/
	return 0;
}

