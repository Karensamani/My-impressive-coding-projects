
#include <bits/stdc++.h>

using namespace std;

const int maxn = 101;

long long int a[maxn];

long long int damage(int n, long long int k, long long int h) // O(N)
{
	long long int sum = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[i + 1] - a[i] >= k)
			sum += k;
		else
			sum += (a[i + 1] - a[i]);

		if(sum >= h)
			return sum;
	}
	sum += k;

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--)
	{
		long long int n, h;
		cin >> n >> h;

		for(int i = 1; i <= n; i++) //  O(n)
			cin >> a[i];

		long long int L = 0;
		long long int R = h;


		while(R - L > 1LL) // O(log n)
		{
			long long int mid = (L + R) / 2LL;

			long long int sum = damage(n, mid, h);

			if(sum < h)
				L = mid;
			else
				R = mid;
		}
		cout << R << endl;

		for(int i = 1; i <= n; i++) // O(n)
			a[i] = 0;
	}
	return 0;
}
