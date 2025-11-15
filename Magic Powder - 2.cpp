#include <bits/stdc++.h>
using namespace std;

bool check(long long cur, int n, int k, int a[], int b[])
{
    long long powder = 0;
    for(int i = 0; i < n; ++i)
    {
        long long need = a[i] * cur;
        if(need > b[i])
        {
            powder += need - b[i];
            if(powder > k)
                return false;
        }
    }
    return powder <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n], b[n];

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    long long l = 0, r = 2e9 + 10;

    while(l < r)
    {
        long long mid = (l + r + 1) / 2;

        if(check(mid, n, k, a, b))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;

    return 0;
}
