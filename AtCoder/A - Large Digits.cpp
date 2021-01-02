#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	int aa(0), bb(0);
	for (int i = 0; i < 3; i++)
	{
		aa += a % 10;
		bb += b % 10;

		a /= 10;
		b /= 10;
	}

	cout << max(aa, bb);

	return 0;
}
