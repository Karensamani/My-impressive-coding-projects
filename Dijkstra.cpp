#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;

vector <pair <long long, int> > adj[maxn];

long long hig[maxn];
int par[maxn];

vector <int> ans;

priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > pq;

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    for(int i = 1; i <= n; i++)
    {
        hig[i] = 1e18;
        par[i] = 0;
    }

    hig[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d != hig[u])
            continue;

        for(auto edge : adj[u])
        {
            long long w = edge.first;
            int v = edge.second;

            if(hig[u] + w < hig[v])
            {
                hig[v] = hig[u] + w;
                par[v] = u;
                pq.push({hig[v], v});
            }
        }
    }

    if (hig[n] == 1e18)
        cout << -1;
    else
    {
        for(int v = n; v; v = par[v])
            ans.push_back(v);

        reverse(ans.begin(), ans.end());

        for(int v : ans)
            cout << v << " ";
    }

    return 0;
}
