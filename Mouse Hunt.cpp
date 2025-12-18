#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n, c[maxn], a[maxn];

vector <int> adj[maxn];

int tot = 0, color = 1;

int mark[maxn], par[maxn];

vector <pair <int, int> > cycle;

void dfs(int u)
{
    mark[u] = color;

    for(int v : adj[u])
    {
        if(mark[v] == 0)
        {
            par[v] = u;
            dfs(v);
        }
        else
        {
            if(mark[u] == mark[v])
            {
                cycle.push_back({u, v});
            }
        }
    }
}

int32_t main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        adj[i].push_back(a[i]);
    }

    for(int i = 1; i <= n; ++i)
    {
//        if(a[i] == i)
//        {
//            tot += c[i];
//            mark[i] = color++;
//            continue;
//        }

        if(mark[i] == 0)
        {
            dfs(i);
            color++;
        }
    }

    for(pair <int, int> p : cycle)
    {
//        cout << p.first << ' ' << p.second << endl;
        int cur = p.first;
        int minc = 1e9;
        while(cur != p.second)
        {
            minc = min(minc, c[cur]);
            cur = par[cur];
        }
        minc = min(minc, c[cur]);
        tot += minc;
    }

    cout << tot << endl;

    return 0;
}
