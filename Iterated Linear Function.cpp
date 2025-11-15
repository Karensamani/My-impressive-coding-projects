#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long int mod_power(long long int a, long long int b, long long int mod) 
{
    long long int res = 1;
    a %= mod;
    
    while(b > 0)
	{
        if(b % 2) 
            res = (res * a) % mod;
        
		a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long int mod_div(long long int a, long long int b, long long int mod)
{
	return a * mod_power(b, mod - 2, mod) % mod;
}


int main()
{
	long long int a, b, n, x;
	cin >> a >> b >> n >> x;
	
	if(a == 1) 
	{
        long long int ans = (x + (n % mod) * b) % mod;
        cout << ans << endl;
        return 0;
    }
	
	long long int ans_1 = (mod_power(a, n, mod) * x) % mod;
	long long int ans_2 = ((mod_power(a, n - 1, mod) - 1) * a) % mod;
	ans_2 = mod_div(ans_2, (a - 1), mod) + 1;
	ans_2 = (ans_2 * b) % mod;
	
	long long int ans = (ans_1 + ans_2) % mod;
	
	cout << ans << endl;
	return 0; 
}
