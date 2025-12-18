#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
long long a[maxn], ps[maxn];
long long k;
int n;

long long costL(long long L)
{
    int pos = lower_bound(a, a + n, L) - a;
    if(pos == 0)
        return 0;

    return L * pos - ps[pos - 1];
}

long long costR(long long R)
{
    int pos = upper_bound(a, a + n, R) - a;
    if(pos == n)
        return 0;
    long long sum = ps[n - 1];
    if(pos > 0)
        sum -= ps[pos - 1];
    return sum - R * (n - pos);
}

bool check(long long diff)
{
    for(int i = 0; i < n; ++i)
    {
        long long L = a[i];
        long long R = L + diff;
        if(costL(L) + costR(R) <= k)
            return true;
    }

    for(int i = 0; i < n; ++i)
    {
        long long R = a[i];
        long long L = R - diff;
        if(costL(L) + costR(R) <= k)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    ps[0] = a[0];
    for(int i = 1; i < n; ++i)
        ps[i] = ps[i - 1] + a[i];

    long long L = 0, R = a[n - 1] - a[0];
    long long ans = R;

    while(L <= R)
    {
        long long mid1 = L + (R - L) / 3;
        long long mid2 = R - (R - L) / 3;

        bool c1 = check(mid1);
        bool c2 = check(mid2);

        if(c1)
        {
            ans = mid1;
            R = mid1 - 1;
        }
        else if(c2)
        {
            ans = mid2;
            L = mid1 + 1;
            R = mid2 - 1;
        }
        else
            L = mid2 + 1;
    }

    cout << ans << endl;
    return 0;
}
