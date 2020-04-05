#include <iostream>		// 백준 12840

using namespace std;

typedef long long int ll;

const int DAY = 60 * 60 * 24;
const int H = 60 * 60;
const int M = 60;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll total(0);
	int h, m, s;
	cin >> h >> m >> s;
	total = H * h + M * m + s;

	int T;
	int query(0);
	int temp(0);
	cin >> T;

	while (T--)
	{
		cin >> query;
		if (query == 1)
		{
			cin >> temp;
			total = (total + temp) % DAY;
		}
		else if (query == 2)
		{
			cin >> temp;
			total = (total - temp) % DAY;
			if (total < 0)
				total += DAY;
		}
		else
			cout << total / H << " " << (total % H) / M << " " << total % M << "\n";
	}

	return 0;
}
