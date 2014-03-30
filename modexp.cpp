#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>

#define rep(i, s, n) for(i = (s); i < (n); i++)
#define LIM 1000000000

using namespace std;

ostringstream op;

/*
	x**n = [x**2]**n/2
	
	Hence, the exponent decreases logarithmically, leading to a running time of O(log n).
	res = modexp(x*x%mod, n/2, mod)
	Now, since we deal with only integral operations(no floating points), n/2 will be an integer. If n is odd, we need to account for the x**0.5 that is lost in the float to integer conversion.
	Hence, for odd n:
		res = x*modexp(x*x%mod, n/2, mod)
			
*/

long long modexp(long long a, long long b, long long c){
	
	if(b == 0)
		return 1;
	if(b == 1)
		return a%c;
	long long res = modexp(a*a%c, b/2, c);
	if(b%2 == 1)
		res = res*a%c;
	return res;
}

void pv(vector<int> v){
	op << "[";
	for(int i = 0; i < v.size(); i++)
		op << v[i] << " ";
	op << "]" << endl;
}

void printarr(int *a, int n){
	int i;
	rep(i, 0, n)
		op << a[i]<< " ";
	op << endl;
}

int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	//clock_t t_start, t_end;
	//t_start = clock();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		op << modexp(n, k, 1000000007) << endl;
	}
	//t_end = clock();
	//op << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

