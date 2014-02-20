/*

Sample Input 1:
ABABABABABABACABABABABABABAC
ABAC

Sample Output 2:
String: ABABABABABABACABABABABABABAC
Pattern: ABAC
Matches: 2
Indices: 11 25 

Sample Input 2:
ABAC 
T

Sample Output 2:
String: ABAC
Pattern: T
Matches: 0
Indices: Nil

*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define LIM 1001

int ind[LIM] = {};
int ctr;
char str[LIM] = {};
char p[LIM] = {};

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

int kmp(char *s, int n, char *pat, int m){
	int i, j, len;
	char lp[LIM] = {};
	ctr = 0;
	lp[0] = 0;
	len = 0;
	rep(i, 1,  m){
		if(pat[i] == pat[len]){
			lp[i] = ++len;
		}
		else{
			if(len){
				len = lp[len - 1];
				i--;
			}
			else lp[i] = 0;
		}
	}
	
	i = j = 0;
	while(i < n){
		if(s[i] == pat[j]){
			i++;
			j++;
		}
		if(j == m){
			ind[ctr] = i + 1 - m;
			ctr++;
			j = lp[j-1];
		}
		if(s[i] != pat[j]){
			if(j)
				j = lp[j-1];
			else
				i++;
		}
	}
	return ctr;
}


int main(int argc, char **argv){
	int x;
	scanf("%[^\n]%s", str, p); // Not a good idea for taking string inputs, but the focus is not on the input in this program. For real life purposes, use fgets()
	x = kmp(str, strlen(str), p, strlen(p));
	printf("String: %s\nPattern: %s\nMatches: %d\n", str, p, x);
	printf("Indices: ");
	if(ctr)
		printarr(ind, ctr);
	else printf("Nil\n");
	return 0;
}

