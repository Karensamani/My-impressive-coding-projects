#include <bits/stdc++.h>

using namespace std;

const int maxn = 27;

vector <vector <char> > adj(27);

vector <pair <char, char> > ans;

bool mark[27];

int par[maxn];

void dfs(int v)
{
    mark[v] = 1;

    for(int u : adj[v])
    {
        if(not mark[u])
        {
            par[u] = v;
            ans.push_back({u + 96, v + 96});

            dfs(u);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < n; ++i)
    {
        if(s1[i] == s2[i])
            continue;
        adj[s1[i] - 96].push_back(s2[i] - 96);
        adj[s2[i] - 96].push_back(s1[i] - 96);
    }

    int col = 1;

    for(int i = 1; i <= 26; ++i)
    {
        if(not mark[i])
        {
            dfs(i);
            col++;
        }
    }

    cout << 26 - col + 1 << endl;

    for(int i = 0; i < ans.size(); ++i)
    {
        if(ans[i].first != 0 && ans[i].second != 0)
            cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
