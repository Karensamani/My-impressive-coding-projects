#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
        int n, m = 0;
        cin >> n;
        int arr[n + 5];
        int cnt[maxn];

        for(int i = 0; i < n; ++i)
        {
                cin >> arr[i];
                m = max(m, arr[i]);
        }

        for(int i = 0; i < n; ++i)
        {
                cnt[arr[i]]++;
        }

        int dp[maxn];
        dp[0] = 0;
        dp[1] = cnt[1];

        for(int i = 0; i < maxn; ++i)
        {
                dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }

        cout << dp[m] << endl;

        return 0;
}
