#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int L = 1, R = 999;

        while(R - L > 1)
        {
            int mid1 = L + ceil(1.0 * (R - L) / 3.0);
            int mid2 = R - (R - L) / 3;

            cout << "? " << mid1 << " " << mid2 << endl;

            int ans;
            cin >> ans;

            if(ans == (mid1 + 1) * (mid2 + 1))
                R = mid1;
            else if(ans == mid1 * (mid2 + 1))
            {
                L = mid1;
                R = mid2;
            }
            else if(ans == mid2 * mid1)
                L = mid2;
        }
        cout << "! " << R << endl;
    }
    return 0;
}
