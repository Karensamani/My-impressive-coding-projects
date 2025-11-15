#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin, v.end()
#define fr first
#define sc second
#define pb push_back
#define mp make_pair


const int mod = 1e9 + 7;
const int maxn = 2e3 + 100;
long long int mark[maxn];
long long int dp[maxn][maxn];

int main()
{
    int n, k;
    cin >> n >> k;


    for(long long int i = 1; i <= n; ++i)
        dp[1][i] = 1; 
    
    for(long long int lenght = 2; lenght <= k; ++lenght)
    {
        for(long long int i = 1; i <= n; ++i)
        {
            for(long long int j = i; j <= n; j += i)
            {
                dp[lenght][j] = (dp[lenght][j] + dp[lenght - 1][i]) % mod;
            }
        }
    }

    long long int ans = 0;

    for(long long int i = 1; i <= n; ++i)
        ans = (ans + dp[k][i]) % mod;

    cout << ans << endl;
    return 0;
}
