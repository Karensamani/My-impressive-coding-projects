#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    long long d = 1;
    long long ans = 1;

    int i = 0;
    while(i < n)
    {
        long long a = arr[i];
        long long c = 0;

        while(i < n && arr[i] == a)
        {
            c++;
            i++;
        }

        long long s = c * (c + 1) / 2;

        long long f = 1;
        long long base = a;
        long long exp = s;
        while(exp > 0)
        {
            if(exp % 2 == 1)
                f = f * base % mod;
            base = base * base % mod;
            exp /= 2;
        }

        long long t1 = 1;
        base = ans;
        exp = c + 1;
        while(exp > 0)
        {
            if (exp % 2 == 1)
                t1 = t1 * base % mod;
            base = base * base % mod;
            exp /= 2;
        }

        long long t2 = 1;
        base = f;
        exp = d;
        while(exp > 0)
        {
            if(exp % 2 == 1)
                t2 = t2 * base % mod;
            base = base * base % mod;
            exp /= 2;
        }

        ans = t1 * t2 % mod;
        d = d * (c + 1) % (mod - 1);
    }

    cout << ans << endl;
    return 0;
}
