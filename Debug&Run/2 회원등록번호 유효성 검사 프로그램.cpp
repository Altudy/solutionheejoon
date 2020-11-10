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
	int basic(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
		basic += temp;
	}

	int score(1), sum(0);
	int cnt(0);
	sum += score;

	for (int i = 1; i < n; i++)
	{
		if (v[i] == 1 && v[i-1] ==1)
		{
			score++;
			sum += score;
			cnt = 0;
		}
		else if (v[i] == 1 && v[i - 1] == 0)
		{
			score = 1;
			sum += score;
			cnt = 0;
		}
		else if (v[i] == 0 && v[i - 1] == 0)
		{
			cnt++;
			if (cnt == 2)
			{
				cout << basic; return 0;
			}
		}

	}
	cout << sum;

	return 0;
}
