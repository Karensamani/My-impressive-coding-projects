#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin >> n;

    multiset <int> s;
    vector <int> vec;
    for(int i = 0; i < n * n; ++i)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    auto it = s.end();
    it--;
    vec.pb(*it);
    s.ers(it);

    for(int i = n * n - 2; i >= 0; --i)
    {
        auto itt = s.end();
        itt--;
        vec.pb(*itt);
        s.ers(itt);

        for(int j = 0; j < vec.size() - 1; ++j)
        {
            s.ers(s.lb(__gcd(vec[vec.size() - 1], vec[j])));
            s.ers(s.lb(__gcd(vec[vec.size() - 1], vec[j])));
        }
        if(vec.size() == n)
            break;
    }
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    return 0;
}
