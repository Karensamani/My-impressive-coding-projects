#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 100;
int a[maxn][maxn], sz[maxn * maxn];
char grid[maxn][maxn];
bool color[maxn][maxn];
int result[maxn][maxn];
int n, m;

int G[4] = {1, 0, 0, -1};
int H[4] = {0, 1, -1, 0};

void dfs(int x, int y, int num)
{
    color[x][y] = true;
    a[x][y] = num;
    sz[num]++;

    for(int i = 0; i < 4; ++i)
    {
        int nx = x + G[i];
        int ny = y + H[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(grid[nx][ny] == '*' || color[nx][ny])
            continue;
        dfs(nx, ny, num);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    int cnt = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(grid[i][j] == '.' && !color[i][j])
            {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }

    vector <int> adj;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(grid[i][j] != '*')
                continue;

            adj.clear();
            for(int k = 0; k < 4; ++k)
            {
                int nx = i + G[k];
                int ny = j + H[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if(grid[nx][ny] == '*' || !color[nx][ny])
                    continue;

                adj.push_back(a[nx][ny]);
            }

            sort(adj.begin(), adj.end());

            vector <int> tmp;

            for(int k = 0; k < adj.size(); ++k)
            {
                if(k == 0 || adj[k] != adj[k - 1])
                    tmp.push_back(adj[k]);
            }
            int ans = 0;
            for(int k : tmp)
                ans += sz[k];

            result[i][j] = (ans + 1) % 10;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(grid[i][j] == '.')
                cout << grid[i][j];
            else
                cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}
