#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, temp;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	vector<bool> chk;
	chk.assign(n, false);

	int a;

	for (int i = 1; i < n; i++)
	{
		a = abs(v[i] - v[i - 1]);
		if (chk[a] == true) {
			cout << "NFN"; return 0;
		}
		chk[a] = true;
	}

	bool fn=true;

	for (int i = 1; i < n; i++)
	{
		if (chk[i] == false) {
			fn = false;
		}
		else
			if (!fn)
			{
				cout << "NFN"; return 0;
			}
	}
	cout << "FN";

	return 0;
}
