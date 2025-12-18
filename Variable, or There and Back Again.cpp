#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
vector <int> adj[maxn], radj[maxn];
int c[maxn];
bool mark1[maxn], mark2[maxn], res[maxn];

void dfs(int v)
{
    mark1[v] = true;

    for(int u : adj[v])
    {
        if(!mark1[u] && c[u] != 1)
            dfs(u);
    }
}

void rdfs(int v)
{
    mark2[v] = true;

    if(c[v] == 1)
        return;

    for(int u : radj[v])
    {
        if(!mark2[u])
            rdfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        cin >> c[i];

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(c[i] == 1 && !mark1[i])
            dfs(i);
    }

    for(int i = 1; i <= n; ++i)
    {
        if(c[i] == 2 && !mark2[i])
            rdfs(i);
    }

    for(int i = 1; i <= n; ++i)
        cout << (mark1[i] && mark2[i]) << endl;

    return 0;
}
