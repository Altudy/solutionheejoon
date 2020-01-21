#include <iostream>
#include <vector>
using namespace std;

constexpr long long	MOD = 1000000007LL;

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	vector<vector<int>> v;
	v.assign(m * 2 + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
		v[1][i] = i;

	for (int i = 2; i <= m * 2; i++)
	{
		v[i][1] = 1;
		for (int j = 2; j <= n; j++)
		{
			v[i][j] = (v[i][j - 1] + v[i - 1][j]) % MOD;
		}
	}
	cout << v[m * 2][n];
	return 0;
}
