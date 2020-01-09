#include <iostream>		//CF 1281 B
#include <string>
#include <algorithm>
using namespace std;

int t;
string a, b;
char temp(0);
bool chk;

int main()
{
	ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		chk = false;
		if (a < b) cout << a << endl;
		else
		{
			for (int i = 0; i < min(a.length(), b.length()); i++)
			{
				for (int j = i+1; j < a.length(); j++)
				{
					if (b[i] < a[j]) continue;
					if (a[i] == a[j]) continue;
					swap(a[i], a[j]);
					if (a < b)
					{
						cout << a << endl;
						chk = true;
						break;
					}
					else
						swap(a[i], a[j]);
				}
				if (chk) break;
				if (!chk && a[i] > b[i]) break;
			}
			if (!chk)
				cout << "---" << endl;
		}
	}
	return 0;
}
