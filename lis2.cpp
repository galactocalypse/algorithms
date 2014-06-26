/*
	Program to find the length of the longest increasing subsequence in a sequence of numbers.
	To find the actual sequence, we need to store the indices of the elements instead of the actual values in the dp array.
	Then, while finding the index of the largest element less than a given element, the index can be stored as the parent(predecessor) of the element being processed.
	
	This approach has a running time of O(nlogn) and uses O(n) auxiliary space.
	
	Sample input:
	9
	2 5 3 7 11 8 7 9 6

	Sample output:
	5
	
*/

#include<iostream>
using namespace std;
int bs(int *arr, int l, int r, int s){
	//Returns index of smallest element >= s
	if(r < l)
		return -1;
	int m = (r+l)/2;
	if(l == r){
		if(s <= arr[l])
			return l;
		else return -1;
	}
	if(arr[m] < s){
		return bs(arr, m+1, r, s);
	}
	return bs(arr, l, m, s);
}

int main(){
	int n;
	cin >> n;
	int arr[n+1];
	for(int i = 0; i < n; i++){
		cin >> arr[i+1];
	}
	int dp[n];
	dp[1] = arr[1];
	int len = 1;
	for(int i = 2; i <= n; i++){
		int ele = bs(dp, 1, len, arr[i]);

		if(ele == -1){//no element in dp is >= arr[i]
			dp[++len] = arr[i];
		}
		else dp[ele] = arr[i];
	}
	cout << len << endl;
	return 0;
}

