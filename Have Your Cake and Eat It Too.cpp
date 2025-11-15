#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int nums[4][maxn], n, total, target;

int ans[4][2];

bool can(int a, int b, int c)
{
    int ind1 = -1, sum1 = 0;
    int ind2 = -1, sum2 = 0;
    int sum3 = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum1 += nums[a][i];
        if(sum1 >= target)
        {
            ind1 = i;
            break;
        }
    }
    for(int i = ind1 + 1; i <= n; ++i)
    {
        sum2 += nums[b][i];
        if(sum2 >= target)
        {
            ind2 = i;
            break;
        }
    }
    if(ind2 == -1)
        return false;

    for(int i = ind2 + 1; i <= n; ++i)
    {
        sum3 += nums[c][i];
    }
    if(sum3 < target)
        return false;
    else
    {
        ans[a][0] = 1;
        ans[a][1] = ind1;

        ans[b][0] = ind1 + 1;
        ans[b][1] = ind2;

        ans[c][0] = ind2 + 1;
        ans[c][1] = n;

//        ans1 = ind1;
//        ans2 = ind2;
        return true;
    }
}

int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= 3; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cin >> nums[i][j];
                if(i == 3)
                {
                    total += nums[i][j];
                }
            }
        }
        target = ceil((total * 1.0) / 3.0);

        int permu[6][3] = {
                        {1, 2, 3},
                        {1, 3, 2},
                        {2, 1, 3},
                        {2, 3, 1},
                        {3, 1, 2},
                        {3, 2, 1},
        };

        bool ok = false;
        for(int i = 0; i < 6; ++i)
        {
            if(can(permu[i][0], permu[i][1], permu[i][2]))
            {

                cout << ans[1][0] << " " << ans[1][1] << ' ' << ans[2][0] << ' ' << ans[2][1] << ' ' << ans[3][0] << ' ' << ans[3][1] << endl;

                ok = 1;
                break;
            }
        }
        if(not ok)
        {
            cout << -1 << endl;
        }

        total = 0;
    }

    return 0;
}
