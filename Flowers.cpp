#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int maxn = (1000*100) + 5;
const ll mod = 1000000007;
int dp[maxn];
int ps[maxn];

int main()
{
    int t, k;
    cin >> t >> k;

    dp[0] = 1;
    for(int i = 1; i < maxn; ++i)
    {
        dp[i] = dp[i - 1];

        if(i >= k)
            dp[i] = (dp[i] + dp[i - k]) % mod;
    }

    for(int i = 1; i < maxn; ++i)
        ps[i] = (ps[i - 1] + dp[i]) % mod;

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        ll ans = (ps[b] - ps[a - 1] + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
