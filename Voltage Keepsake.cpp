#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

const int maxn = 1e5 + 100;
int a[maxn];
int b[maxn];

bool check_mid(long double mid, int n, int p)
{
    long double total = 0;
    for(int i = 0; i < n; ++i)
    {
        if(mid * a[i] > b[i])
            total += ((mid * a[i]) - b[i]) / p;
    }

    return total <= mid;
}

int main()
{
    int n, p;
    cin >> n >> p;

    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    long long int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i];

    if(sum <= p)
    {
        cout << -1 << endl;
        return 0;
    }

    long double L = 0, R = 1e14 + 10;

    int loop = 200;
    while(loop--)
    {
        long double mid = (L + R) / 2;

        if(check_mid(mid, n, p))
            L = mid;
        else
            R = mid;
    }

    cout << fixed << setprecision(10) << L << endl;
    return 0;
}
