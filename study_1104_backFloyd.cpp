#include <iostream>		// 백준 1507
using namespace std;

int n;
int d[21][21];
bool c[21][21]{};		// 선이 있으면 false

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i == j || j == k || k == i) continue;
				if (d[i][j] == d[i][k] + d[k][j]) c[i][j] = true;
				else if (d[i][j] > d[i][k] + d[k][j]) {
					cout << "-1"; return 0;
				}
			}

	int ans(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (c[i][j] == false) ans += d[i][j];
	cout << ans/2;
	return 0;
}