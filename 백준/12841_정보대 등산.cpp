#include <iostream>		// 백준 12841
#include <limits.h>
#include <vector>
using namespace std;

typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> cross(n);
	vector<ll> left(n);
	vector<ll> right(n);

	for (int i = 0; i < n; i++)
		cin >> cross[i];

	for (int i = 1; i < n; i++)
	{
		cin >> left[i];
		left[i] += left[i - 1];
	}

	for (int i = 1; i < n; i++)
	{
		cin >> right[i];
		right[i] += right[i - 1];
	}

	int ans = 0;
	int sum = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (sum > left[i] - right[i] + cross[i])
		{
			sum = left[i] - right[i] + cross[i];
			ans = i;
		}
	}
	cout << ans + 1 << " " << sum + right[n - 1];
	return 0;
}
