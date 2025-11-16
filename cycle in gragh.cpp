#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define all(v) v.begin, v.end()
typedef long long ll;

const int maxn = 1e5 + 100;
vector <int> adj[maxn];
bool mark[maxn];
int par[maxn], hig[maxn];

void dfs(int v, int k)
{
    mark[v] = 1;

    for(int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];
        if(!mark[u])
        {
            par[u] = v;
            hig[u] = hig[v] + 1;
            dfs(u, k);
        }
        else
        {
            if(u == par[v])
                continue;
            if(hig[u] > hig[v])
                continue;

            if(hig[v] - hig[u] + 1 >= k + 1)
            {
                cout << hig[v] - hig[u] + 1 << endl;
				int cur = v;
				while(cur != u)
				{
					cout << cur << " ";
					cur = par[cur];
				}
				cout << cur << " ";

				exit(0);
            }
            else
                continue;
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }

    hig[1] = 1;
    par[1] = 1;
    dfs(1, k);

    return 0;
}
