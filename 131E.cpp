#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;

int x[maxn], y[maxn];

int arr[maxn], cnt[maxn], ans[10], n;

int pri[maxn], sec[maxn];

bool cmp(int a,int b)
{
    return (pri[a] == pri[b]) ? (sec[a] < sec[b]) : (pri[a] < pri[b]);
}

void calc()
{
    for(int i = 0; i < n; ++i)
    {
        int r = i + 1;

        while(r < n and pri[arr[r]] == pri[arr[i]])
            r++;

        if(r - i <= 1)
        {
            i = r-1;
            continue;
        }

        for(int j = i; j < r; ++j)
            cnt[arr[j]] += 2;

        cnt[arr[i]]--, cnt[arr[r - 1]]--;

        i = r - 1;
    }
}


int main()
{
    int page_size;
    cin >> page_size >> n;

    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    iota(arr, arr + n, 0);

    for(int i = 0; i < n; ++i)
        pri[i] = x[i] , sec[i] = y[i];

    sort(arr, arr + n, cmp);
    calc();

    for(int i = 0; i < n; ++i)
        pri[i] = x[i]+y[i] , sec[i] = y[i];

    sort(arr,arr+n,cmp);
    calc();

    for(int i = 0; i < n; ++i)
        pri[i] = x[i]-y[i] , sec[i] = y[i];

    sort(arr, arr + n, cmp);
    calc();

    for(int i = 0; i < n; ++i)
        pri[i] = y[i] , sec[i] = x[i];

    sort(arr, arr + n, cmp);
    calc();

    for(int i = 0; i < n; ++i)
        ans[cnt[i]]++;

    for(int i = 0; i < 9; ++i)
        cout << ans[i] << " ";

    cout << endl;
}
