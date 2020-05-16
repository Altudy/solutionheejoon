#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	int n, m;

	while (T--)
	{
		cin >> n >> m;
		if (n == 1)
			cout << 0;
		else if (n == 2)
			cout << m;
		else
			cout << m * 2;
		cout << "\n";
	}
	return 0;
}
