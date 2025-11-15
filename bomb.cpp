#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fr first
#define sc second
#define make_pair
#define pb push_back
#define endl "\n"
#define ll long long

bool check(int mid, int a[], int b[], int n, int k)
{
    long long int total = 0;

    for(int i = 0; i < n ; ++i)
    {
        if(a[i] >= mid)
        {
            int m = (a[i] - mid) / b[i] + 1;
            total += m;
        }
    }

    if(total >= k)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n + 5], b[n + 5];

        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];

        int L = 0, R = 1e9 + 1;

        while(R - L > 1)
        {
            int mid = (R + L) / 2;

            if(check(mid, a, b, n, k))
                L = mid;
            else
                R = mid;
        }

        ll int ans = 0;
        int total_operations = 0;

        for(int i = 0; i < n; ++i)
        {
            if(a[i] >= L)
            {
                int m = (a[i] - L) / b[i] + 1;
                ans += 1LL * m * a[i] - 1LL * m * (m - 1) / 2 * b[i];
                total_operations += m;
            }
        }

        ans -= 1LL * L * (total_operations - k);

        cout << ans << endl;
    }
    return 0;
}
