#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 5];

    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    int cnt_1 = count(arr, arr + n, 1);

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == 1)
            arr[i] = -1;
        else
            arr[i] = 1;
    }

    int c = 0, max_sum = arr[0];

    for(int i = 0; i < n; i++)
    {
        c = max(arr[i], c + arr[i]);
        max_sum = max(max_sum, c);
    }

    cout << max_sum + cnt_1 << endl;
    return 0;
}
