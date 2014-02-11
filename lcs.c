#include<stdio.h>
#include<string.h>
#define LIM 1001
#define max(a, b) ((a)>(b)?(a):(b))

int dp[LIM][LIM] = {0};
char seq[LIM] = {0};

/*top-down
 The array dp needs to be normalized if the actual sequence if to be generated and this function is used
*/
int lcs(char *a, int i, char *b, int j){
	if(i < 0 || j < 0)return 0;
	if(dp[i][j] != -1)return dp[i][j];
	if(a[i] == b[j]){
		return dp[i][j] = 1 + lcs(a, i-1, b, j-1);
	}
	else return dp[i][j] = max(lcs(a, i-1, b, j), lcs(a, i, b, j-1));
}

void normalize(int m, int n){
	/* to get rid of the -1 values for cells which haven't been processed */
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(dp[i][j] == -1){
				if(i == 0 || j == 0)dp[i][j] = 0;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
}

int printseq1(char *a, int m, char *b, int n){//top-down
	int i = 0, j = 0, p = 0;
	while(i < m && j < n){
		if(a[i] == b[j]){
			seq[p++] = a[i];
			i++;
			j++;
		}
		else if(dp[i+1][j] >= dp[i][j+1])i++;
		else j++;
	}
	seq[p] = '\0';
	return p;
}

/*bottom-up*/
int lcs2(char *a, int m, char *b, int n){
	int i, j;
	for(i = m; i >= 0; i--){
		for(j = n; j >= 0; j--){
			if(a[i] == '\0' || b[j] == '\0')dp[i][j] = 0;
			else if(a[i] == b[j])dp[i][j] = 1 + dp[i+1][j+1];
			else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
	return dp[0][0];
}

int printseq2(char *a, int m, char *b, int n){//bottom-up
	int i = 0, j = 0, p = 0;
	while(i < m && j < n){
		if(a[i] == b[j]){
			seq[p++] = a[i];
			i++;
			j++;
		}
		else if(!dp[i][j])break;
		else if(i == m-1)j++;
		else if(j == n-1)i++;
		else if(dp[i+1][j] >= dp[i][j+1])i++;
		else j++;
	}
	seq[p] = '\0';
	return p;
}

int main(void){
	int l, i, j, len;
	char a[1001], b[1001];
	scanf("%s\n%s", a, b);
	memset(dp, -1, 1001*1001*sizeof(int));
	
	printf("Top-down computation:\n");
	l = lcs(a, strlen(a) - 1, b, strlen(b) - 1);
	normalize(strlen(a), strlen(b));
	printf("Length of LCS: %d\n", l);
	len = printseq1(a, strlen(a), b, strlen(b));
	printf("Sequence of length %d: %s\n", len, seq);
	
	printf("\nBottom-up computation:\n");
	l = lcs2(a, strlen(a), b, strlen(b));
	printf("Length of LCS: %d\n", l);
	len = printseq2(a, strlen(a), b, strlen(b));
	printf("Sequence of length %d: %s\n", len, seq);
	return 0;
}

