#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define sc second
#define fr first

bool check(long double t, int n, int l, int v1, int v2, int k)
{
    int groups = (n + k - 1) / k;
    long double pos = 0.0;
    long double time_left = t;

    for (int i = 0; i < groups; i++)
    {
        long double bus_dist = l - pos;
        long double walk_dist = v1 * time_left;

        if (bus_dist <= walk_dist)
            return true;

        long double ride_time = (bus_dist - walk_dist) / (v2 - v1);

        if (ride_time > time_left)
            return false;

        pos += v1 * ride_time;
        time_left -= ride_time;

        if (i < groups - 1)
        {
            long double return_time = (v2 * ride_time - v1 * ride_time) / (v2 + v1);
            if (return_time > time_left) return false;
            time_left -= return_time;
            pos += v1 * return_time;
        }
    }

    return true;
}

int main()
{
    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    int loop = 100;
    long double ans = (long double)l / v1;
    long double L = 0, R = (long double)l / v1;

    while(loop--)
    {
        long double mid = (L + R) / 2;
        if(check(mid, n, l, v1, v2, k))
            ans = mid, R = mid;
        else
            L = mid;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
