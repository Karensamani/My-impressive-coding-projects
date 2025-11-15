#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n + 5][m + 5];

        for(int i = 0; i < n;++i)
            for(int j = 0; j < m; ++j)
                cin >> a[i][j];

        int cnt[n + m][2] = {0};

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cnt[i+j][a[i][j]]++;


        int ans = 0;
        for(int i = 0; i <= n - 1 + m - 1; ++i)
        {
            int k = n - 1 + m - 1 - i;
            if(i!=k)
                ans += min(cnt[i][0] + cnt[k][0], cnt[i][1] + cnt[k][1]);
        }
        cout << ans / 2 << endl;
    }

    return 0;
}

/*
*   *   ***   ****   ***   *   *
*  *   *   *  *   *  *     **  *
***    *****  ****   ***   * * *
*  *   *   *  *   *  *     *  **
*   *  *   *  *   *  ***   *   *
*/
