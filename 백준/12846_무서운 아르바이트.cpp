#include <iostream>		//백준 12846
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

struct Period {	int l, r; };
int wage[100001];
vector<pii> v(100001);
bool visit[100001]{};

Period period[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> wage[i];
		v[i] = { wage[i], i };
	}

	sort(v.begin(), v.end(), greater<pii>());

	for (int i = 0; i < n; ++i)
	{
		int money = v[i].first;
		int idx = v[i].second;
		int left = idx;
		int right = idx;
		
		if (visit[idx]) continue;
		visit[idx] = true;

		while (left >= 1 && wage[left - 1] >= money)
		{
			if (visit[left - 1]) left = period[left - 1].l;
			else visit[--left] = true;
		}
		
		while (right < n - 1 && wage[right + 1] >= money)
		{
			if (visit[right + 1]) right = period[right + 1].r;
			else visit[++right] = true;
		}
		period[left].l = left; period[left].r = right;
		period[right].l = left; period[right].r = right;
		int ans = max(ans, money*(right-left+1));
	}
	cout << ans;

	return 0;
}
