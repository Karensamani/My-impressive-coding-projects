#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;

vector <vector <int> > adj(maxn);

bool mark[maxn];

int dp[maxn], ans[maxn];

vector <long long> products;

vector <pair <int, int> > edge;

void dfs(int v, int block_u, int block_v)
{
    mark[v] = 1;
    int smax = -1, fmax = -1;

    for(int u : adj[v])
    {
        if((v == block_u && u == block_v) || (v == block_v && u == block_u))
            continue;

        if(!mark[u])
        {
            dfs(u, block_u, block_v);

            dp[v] = max(dp[v], dp[u] + 1);
            ans[v] = max(ans[v], ans[u]);

            smax = max(smax, dp[u]);
            if(smax > fmax)
                swap(smax, fmax);
        }
    }

    ans[v] = max(ans[v], smax + fmax + 2);
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
        edge.push_back({u, v});
    }

    for(auto &e : edge)
    {
        int u = e.first, v = e.second;

        memset(mark, 0, sizeof(mark));
        memset(dp, 0, sizeof(dp));
        memset(ans, 0, sizeof(ans));

        dfs(u, u, v);

        int fr = ans[u];

        memset(mark, 0, sizeof(mark));
        memset(dp, 0, sizeof(dp));
        memset(ans, 0, sizeof(ans));

        dfs(v, u, v);

        int sc = ans[v];

        products.push_back(fr * sc);
    }

    cout << *max_element(products.begin(), products.end()) << endl;

    return 0;
}
