#include<iostream>
#include<algorithm>
using namespace std;

int T, n, m, ans(0);
int snack[1000];

int main(int argc, char** argv)
{
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			cin >> snack[i];

		sort(snack, snack+n);

		for (int i = 0; i < n - 1; i++)
		{
			if (snack[n - 1 - i] >= m) continue;
			for (int j = 1; j < n - i; j++)
			{
				if (snack[n - 1 - i] + snack[n - 1 - i - j] > m) continue;
				else if (snack[n - 1 - i] + snack[n - 1 - i - j] == m)
				{
					i = n; j = n; ans = m; break;
				}
				ans = max(ans, snack[n - 1 - i] + snack[n - 1 - i - j]);
			}
		}
		if (ans == 0) cout << "#" << test_case << " -1" << endl;
		else cout << "#" << test_case << " " << ans << endl;
		ans = 0;
	}
	return 0;
}