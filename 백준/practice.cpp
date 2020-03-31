#include <iostream> // 백준 14674
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

struct game
{
	int num;
	ll price;
	ll nice;	//가성비
};

bool cmp(const game &g1, const game &g2)
{
	if (g1.nice * g2.price > g2.nice * g1.price)
		return true;
	else if (g1.nice * g2.price < g2.nice* g1.price)
		return false;
	else
	{
		if (g1.price == g2.price)
			return g1.num < g2.num;
		else
			return g1.price < g2.price;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<game> g(n);

	for (int i = 0; i < n; i++)
		cin >> g[i].num >> g[i].price >> g[i].nice;

	sort(g.begin(), g.end(), cmp);

	for (int i = 0; i < k; i++)
		cout << g[i].num << '\n';

	return 0;
}
