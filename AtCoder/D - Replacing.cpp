#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n, temp;
	ll sum(0);
	cin >> n;

	vector<int> num;
	num.assign(100001, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		num[temp]++;
		sum += temp;
	}

	ll q, bb, cc;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> bb >> cc;
		sum -= num[bb] * bb;
		sum += num[bb] * cc;
		num[cc] += num[bb];
		num[bb] = 0;
		cout << sum << endl;
	}

	return 0;
}
