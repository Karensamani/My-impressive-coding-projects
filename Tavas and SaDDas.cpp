#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    
	int l = 0, ans = 0;

	while(n != 0)
    {
		if(n % 10 == 7)
			ans += pow(2, l);
		n /= 10;
		l++;
	}

	ans += pow(2, l) - 1;
	
	cout << ans << endl;
	
	return 0;
}
