#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back


int32_t main()
{
    ll n, k;
    cin >> n >> k;
    vector <ll> vec;

    for(ll i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            vec.pb(i);
            if(i != n/i)
                vec.pb(n/i);
        }
    }

    if(vec.size() < k)
        cout << -1 << endl;
    else
    {
        sort(vec.begin(), vec.end());
        cout << vec[k - 1] << endl;
    }

    return 0;
}
