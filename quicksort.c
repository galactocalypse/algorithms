/*
	Probably the best way to remember this algorithm is to follow:
	1. Choose(and store) a random element
	2. Move around the others so you have the lower and higher halves
	3. Put that element in its right position
	4. Recursively partition the subarrays.
	Despite the fact that most algorithms state exactly the same thing, I manage to mess the implementation up every single time.
	Hopefully, that won't happen again.

	Sample input:
	10
	3 5 2 4 6 8 9 0 1 7
	Sample output:
	0 1 2 3 4 5 6 7 8 9
	
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 100001

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

void quicksort(int *arr, int s, int e){
	int piv = arr[s]; // can be any element
	int p = s-1, t, i;
	if(e <= s)return;
	
	rep(i, s, e+1){
		if(arr[i] <= piv){
			p++;
			t = arr[p];
			arr[p] = arr[i];
			arr[i] = t;
		}
	}
	arr[s] = arr[p];
	arr[p] = piv;
	
	quicksort(arr, s, p-1);
	quicksort(arr, p+1, e);
}

int main(int argc, char **argv){
	int n, i;
	int arr[LIM] = {};
	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d", &arr[i]);
	}
	quicksort(arr, 0, n-1);
	printarr(arr, n);
	return 0;
}

