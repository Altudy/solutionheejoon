#include <iostream>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
 
	int n;
	int a[3];
	int idx(0);
	while (T--)
	{
		cin >> n;
		idx = 0;
		for (int i = 2; (i * i < n) && (idx < 2); i++)
		{
			if (n % i == 0)
			{
				a[idx] = i;
				n /= a[idx];
				if (n <= a[idx])
					break;
				idx++;
			}
			if (idx == 2)
			{
				a[2] = n;
			}
		}
		if (idx == 2)
		{
			cout << "YES" << endl;
			cout << a[0] << " " << a[1] << " " << a[2] << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}
