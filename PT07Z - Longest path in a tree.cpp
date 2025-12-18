#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;

vector<int> adj[maxn];
bool mark[maxn];
int hig[maxn];
int dp[maxn];

void dfs(int v)
{
    mark[v] = 1;
    hig[v] = 0;
    dp[v] = 0;

    int smax = 0, fmax = 0;

    for(int u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u);
            hig[v] = max(hig[v], hig[u] + 1);
            dp[v] = max(dp[v], dp[u]);

            int d = hig[u] + 1;
            if(d > fmax)
            {
                smax = fmax;
                fmax = d;
            }
            else if(d > smax)
                smax = d;
        }
    }

    dp[v] = max(dp[v], fmax + smax);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int r;
    cin >> r;
    dfs(r);

    int q;
    cin >> q;

    while(q--)
    {
        int s;
        cin >> s;
        cout << dp[s] << endl;
    }

    return 0;
}
