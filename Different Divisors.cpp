#include <bits/stdc++.h>
using namespace std;

#define Gharbal(maxn, mark)                             \
    for(int i = 2; i < (maxn); ++i)                     \
    {                                                   \
        if(!(mark)[i])                                  \
        {                                               \
            for(int j = (i) * 2; j < (maxn); j += (i))  \
                (mark)[j] = true;                       \
        }                                               \
    }


const int maxn = 2e6 + 100;
bool mark[maxn];

long long int smallest_prime(int d, int p)
{
    long long int q = d + p;
    while(true)
    {
        if(!mark[q])
            break;
        q++;
    }
    return q;
}

void solve()
{
    int d;
    cin >> d;
    long long p = smallest_prime(d, 1), q = smallest_prime(d, p);
    long long ans1 = p * q, ans2 = p * p * p;
    cout << min(ans1, ans2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    Gharbal(maxn, mark);


    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

