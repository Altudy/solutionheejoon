#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int T;
	cin >> T;
 
	int n, k;
	vector<int> a;
	vector<int> b;
	int ans = 0;
 
	while (T--)
	{
		cin >> n >> k;
		a.assign(n, 0);
		b.assign(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());
 
		int x = 0;
		int y = 0;
		while (n)
		{
			if (a[x] < b[y] && k>0)			{
				ans += b[y];
				y++; k--;
			}
			else			{
				ans += a[x];
				x++;
			}
			n--;
		}
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
