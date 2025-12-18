#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 100;

#define int long long

int mark[maxn], par[maxn], zir[maxn];

vector <vector <int> > adj(maxn);

void dfs(int v)
{
    zir[v] = 1;
    mark[v] = 1;

    for(int u : adj[v])
    {
        if(not mark[u])
        {
            par[u] = v;
            dfs(u);
            zir[v] += zir[u];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;

    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(x);

    int cur = y, prev = -1;

    while(cur != x)
    {
        prev = cur;
        cur = par[cur];
    }

    int X = n - zir[prev];
    int Y = zir[y];

    int ans =  (n * (n - 1)) - (X * Y);

    cout << ans << endl;

    return 0;
}
