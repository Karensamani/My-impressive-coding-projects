#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
        ans += (2 * i - 1) * i;

	cout << ans << ' ' << 2 * n << endl;

	for(int i = n; i >= 1; i--)
    {
		cout << "1 " << i << ' ';
		for(int j = 1; j <= n; ++j)
            cout << j << ' ';
        cout<<endl;

		cout << "2 " << i << ' ';

		for(int j = 1; j <= n; ++j)
            cout << j << ' ';
        cout << endl;
	}
}

int32_t main()
{
	int n;
	cin >> n;
	while(n--)
        solve();
}
