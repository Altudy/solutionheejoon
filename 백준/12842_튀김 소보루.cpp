# 1. 내가 풀었던 코드, 비효율
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, s, m;
	cin >> n >> s >> m;
	int eat = n - s;

	vector<int> time(m);

	for (int i = 0; i < m; i++)
		cin >> time[i];

	int ans(0);

	for(int i=0; i<100000; i++)
		for (int j = 0; j < m; j++)
			if (i % time[j] == 0)
			{
				ans++;
				if (ans == eat)
				{
					cout << j + 1;
					return 0;
				}
			}
	return 0;
}


/*
2. 개선한 코드
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef long long int ll;

int n, s, m;
vector<int> time;

ll sol(int x)
{
	if (x < 0) return 0;
	ll y = m;
	for (int i = 0; i < m; i++)
		y += x / time[i];
	return y;
}

int main()
{
	scanf("%d %d %d", &n, &s, &m);
	int eat = n - s;
	time.resize(m);

	for (int i = 0; i < m; i++)
		scanf("%d", &time[i]);

	int hi = INT_MAX, lo = -1, mid;
	while (hi > lo + 1)
	{
		mid = (hi + lo) / 2;
		if (sol(mid) < eat)
			lo = mid;
		else
			hi = mid;
	}
	eat -= sol(lo);
	int val = lo + 1;

	for (int i = 0; i < m; i++)
		if (val % time[i] == 0)
		{
			eat--;
			if (eat == 0)
			{
				cout << i + 1;
				return 0;
			}
		}
	return 0;
}

*/


/*
3. pq를 이용한 코드
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, s, m;
	cin >> n >> s >> m;
	int eat = n - s - 1;

	vector<int> time(m);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (int i = 0; i < m; i++)
	{
		cin >> time[i];
		pq.push({ 0, i });
	}

	pii a;
	while (eat--)
	{
		a = pq.top();
		pq.pop();
		pq.push({ a.first + time[a.second], a.second });
	}
	cout << pq.top().second + 1;

	return 0;
}

*/


