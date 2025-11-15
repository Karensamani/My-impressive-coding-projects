#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;

int a[maxn];
int st[maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	st[1] = 1;
	for(int i = 2; i <= n; i++) // O(n)
		st[i] = st[i - 1] + a[i - 1];

	st[n + 1] = st[n] + a[n];

	int q;
	cin >> q;

	for(int i = 1; i <= q; i++) // O(q log n)
	{
		int x;
		cin >> x;

		int L = 1;
		int R = n + 1;

		while(R - L > 1)
		{
			int mid = (L + R) / 2;

			if(st[mid] <= x)
				L = mid;
			else
				R = mid;
		}

		cout << L << endl;
	}
	return 0;
}
