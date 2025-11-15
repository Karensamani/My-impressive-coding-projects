#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int64_t a[n], c[n];
        for(int64_t i = 0; i < n ; ++i)
            cin >> a[i];
        for(int64_t i = 0; i < n; ++i)
            cin >> c[i];

        int64_t dp[n];
        for(int64_t i = 0; i < n; ++i)
            dp[i] = c[i];

        for(int64_t i = 0; i < n; ++i)
        {
            for(int64_t j = 0; j < i; ++j)
            {
                if(a[j] <= a[i])
                    dp[i] = max(dp[i], dp[j] + c[i]);
            }
        }
        cout << accumulate(c, c + n, 0LL) - *max_element(dp, dp + n) << endl;
    }
    return 0;
}
