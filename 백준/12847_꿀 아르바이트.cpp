#include <iostream>		// 백준 12847
using namespace std;

typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	ll sum(0);
	int wage[100001];
	ll ans(0);

	for (int i = 0; i < n; ++i)
	{
		cin >> wage[i];
		sum += wage[i];
		if (i >= m)
			sum -= wage[i - m];
		if (ans < sum) ans = sum;
	}
	cout << ans;

	return 0;
}
