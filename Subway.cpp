#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
vector<int> adj[maxn];
bool mark[maxn];
int par[maxn], hig[maxn];
int ans[maxn];
bool found = false;

vector <pair <int, int> > cycle;

void dfs(int v)
{
    mark[v] = true;

    for(int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];
        if(!mark[u])
        {
            par[u] = v;
            hig[u] = hig[v] + 1;
            dfs(u);
        }
        else
        {
            if(u == par[v])
                continue;
            if(hig[u] > hig[v])
                continue;

            if(!found)
                cycle.push_back({v, u});
        }
    }
}

int cnt;

void nigger_dfs(int v)
{

    mark[v] = true;
    ans[v] = cnt;
    cnt++;

    for(int u : adj[v])
    {
        if(not mark[u] and ans[u] != -1)
            nigger_dfs(u);
    }
    cnt--;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    hig[1] = 1;
    par[1] = 1;
    dfs(1);

    for(pair <int, int> p : cycle)
    {
        found = true;
        int cur = p.first;
        while(cur != p.second)
        {
            ans[cur] = -1;
            cur = par[cur];
        }
        ans[cur] = -1;
    }

    fill(mark + 1, mark + n + 1, false);

    for(int i = 1; i <= n; ++i)
    {
        if(ans[i] == -1)
        {
            nigger_dfs(i);
            cnt = 0;
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";

    return 0;
}
