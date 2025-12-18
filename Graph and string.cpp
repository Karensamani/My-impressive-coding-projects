#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e2 + 100;

vector <int> adj[maxn];

bool mat[maxn][maxn], mark[maxn];

char ans[maxn];

void dfs(int v)
{
    mark[v] = true;

    for(int u : adj[v])
    {
        if(not mark[u])
        {
            ans[u] = ('a' + 'c') - ans[v];
            dfs(u);
        }
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
        mat[u][v] = mat[v][u] = true;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(not mat[i][j] and i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        if(adj[i].size() == 0)
            ans[i] = 'b';
        else if(not mark[i])
        {
            ans[i] = 'a';
            dfs(i);
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i != j and ((mat[i][j] and abs(ans[i] - ans[j]) > 1) or (not mat[i][j] and abs(ans[i] - ans[j]) != 2)))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    for(int i = 1; i <= n; ++i)
        cout << ans[i];
}
