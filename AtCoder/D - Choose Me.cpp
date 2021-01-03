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

typedef long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<ll> v;
	ll a, b;
	ll sum(0);
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(b + a + a);
		sum += a;
	}

	sort(v.begin(), v.end(), greater<ll>());

	for (int i = 0; i < N; i++)
	{
		sum -= v[i];
		if (sum < 0) {
			cout << i + 1; break;
		}
	}

	return 0;
}
