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
#define LIM 100000000
#define M 1000000009

using namespace std;

ostringstream op;

/*
	This function calculates (a^b)%MOD
*/
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

/*
	Modular Multiplicative Inverse
	Using Euler's Theorem
	a^(phi(m)) = 1 (mod m)
	a^(-1) = a^(m-2) (mod m)
*/
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
/*
	Wilson's theorem states that for a prime p,
		(p-1)! = -1 % p
	To find the factorial of a number n (< p, obviously) mod p,
	we divide (-1 % p) by all numbers between p-1 and n+1, inclusive.
	Since, division is not modular((a/b)%m != (a%m / b%m)), we need to
	restrict ourselves to multiplication. Hence, we perform multiplication
	with the modular multiplicative inverses of the numbers instead of dividing
	(-1 % p) with them.
*/

long long fact_wilson(long long n, long long m){
	if(n >= m)
		return 0;
	long long p = (m-1)%m;
	long long r = m-1;
	while(r > n){
		p = p*InverseEuler(r, m)%m;
		r--;
	}
	return p;
}

int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	//clock_t t_start, t_end;
	//t_start = clock();
	int t;
	cin >> t;
	while(t--){
		int p, n;
		cin >> n >> p;
		long long res = fact_wilson(n, p);
		op << res << endl;
	}
  	//t_end = clock();
	//op << (double)(t_end - t_start)/CLOCKS_PER_SEC << "s" << endl;
	cout << op.str();
	return 0;
}

