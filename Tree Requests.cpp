#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000001;

vector <int> child[maxn];

vector <pair <int, int> > h[maxn];

int st[maxn], ft[maxn];

int ps[26];

int timer = 1;

string s;

void dfs(int v, int d)
{
    st[v] = timer++;

    int pre_h = h[d].back().second;

    int new_h = pre_h ^ ps[s[v] - 'a'];

    h[d].push_back({timer, new_h});

    for(int u : child[v])
        dfs(u, d + 1);

    ft[v] = timer++;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < 26; ++i)
        ps[i] = 1 << i;

    for(int i = 0; i < n; ++i)
        h[i].push_back({0, 0});

    for(int i = 0; i < n - 1; ++i)
	{
        int par;
        cin >> par;
        child[par - 1].push_back(i + 1);
    }

    cin >> s;

    dfs(0, 0);

    for(int i = 0; i < m; ++i)
	{
        int v, d;
        cin >> v >> d;
        v--; d--;

        auto L = lower_bound(h[d].begin(), h[d].end(), make_pair(st[v], -1)), R = lower_bound(h[d].begin(), h[d].end(), make_pair(ft[v], -1));

        int l = L - h[d].begin() - 1, r = R - h[d].begin() - 1;

        int sub = h[d][l].second ^ h[d][r].second;

        bool valid = (sub & (sub - 1)) == 0;

        if (valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

