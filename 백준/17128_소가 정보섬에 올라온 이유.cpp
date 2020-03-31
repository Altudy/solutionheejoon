#include <iostream>		// 백준 17128
#include <vector>
using namespace std;

typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= 4; i++)
		a.push_back(a[i]);

	vector<int> mul(n + 1);
	//mul[1] = a[1] * a[2] * a[3] * a[4];
	ll ans = mul[1];
	for (int i = 1; i <= n; i++)
	{
		//mul[i] = mul[i - 1] * a[i + 3] / a[i - 1];
		mul[i] = a[i] * a[i + 1] * a[i + 2] * a[i + 3];
		ans += mul[i];
	}

	int temp;
	for (int i = 0; i < q; i++)
	{
		cin >> temp;
		for (int j = 0; j < 4; j++)
		{
			mul[temp] = -mul[temp];
			ans += 2 * mul[temp];
			if (--temp == 0)
				temp = n;
		}
		cout << ans << '\n';
	}
	return 0;
}
