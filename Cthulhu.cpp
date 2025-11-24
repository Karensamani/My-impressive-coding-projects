#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
vector <int> adj[maxn];
bool mark[maxn];

void dfs(int v)
{
    mark[v] = 1;

    for(int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];
        if(!mark[u])
            dfs(u);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    bool ok = true;
    for(int i = 1; i <= n; ++i)
    {
        if(!mark[i])
        {
            ok = false;
            break;
        }
    }

    if(ok && m == n)
        cout << "FHTAGN!" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
