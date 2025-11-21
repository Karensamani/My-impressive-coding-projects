#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;
int a[maxn], b[maxn];
vector <int> adj[maxn];
bool mark[maxn];
int color[maxn];

void dfs(int v, int col)
{
    mark[v] = 1;
    color[v] = col;

    for(int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];
        if(!mark[u])
            dfs(u, col);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];

    for(int i = 1; i <= n; ++i)
    {
        if(i - b[i] >= 1)
        {
            adj[i].push_back(i - b[i]);
            adj[i - b[i]].push_back(i);
        }
        if(i + b[i] <= n)
        {
            adj[i].push_back(i + b[i]);
            adj[i + b[i]].push_back(i);
        }
    }

    int col = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(!mark[i])
        {
            dfs(a[i], col);
            col++;
        }
    }

    bool ok = true;
    for(int i = 1; i <= n; ++i)
    {
        if(color[a[i]] == color[i])
            continue;
        else
            ok = false;
    }

    if(not ok)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
