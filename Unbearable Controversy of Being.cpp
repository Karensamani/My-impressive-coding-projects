#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("popcnt")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 100;

bool matris[maxn][maxn];

vector <vector <int> > adj(maxn);

int cnt;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        matris[u][v] = true;
        adj[u].push_back(v);
    }

    for(int a = 1; a <= n; a++)
    {
        for(int c = 1; c <= n; c++)
        {
            if(a != c)
            {
                int r = 0;

                for(int b = 0; b < adj[a].size(); b++)
                    if(adj[a][b] != a && adj[a][b] != c && matris[adj[a][b]][c])
                        r++;
                cnt += r * (r - 1) / 2;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
