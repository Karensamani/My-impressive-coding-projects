// copy rights not reserved this is my own code there is no suspection

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;
int a[maxn], b[maxn];

int main()
{
	// ios_base::sync_with_studio(false);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	
	sort(a, a + n);
	
	for(int i = 0; i < m; ++i) // O(m log n)
	{
		// search
		int L = 0, R = n;
		while(R - L > 1) 
		{
			int mid = (R + L) / 2;
			
			if(b[i] >= a[mid])
				L = mid;
			else
				R = mid; 
		}
		
		cout << L + 1 << " ";
	}
	return 0;
}
