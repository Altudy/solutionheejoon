#include <cstdio>			// 백준	14676
#include <vector>
using namespace std;

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	vector<vector<int>> map;
	map.resize(n + 1);

	vector<int> list(n + 1);
	vector<int> degree(n + 1);

	int a, b;
	while(m--)
	{
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		degree[b]++;
	}

	bool ans = true;
	while (k-- && ans)
	{
		scanf("%d %d", &a, &b);
		if (a == 1)
		{
			if (degree[b] > 0) ans = false;
			if (list[b] == 0)
				for (int next : map[b]) degree[next]--;
			list[b]++;
		}
		else
		{
			if (list[b] == 0)	ans = false;
			list[b]--;
			if (list[b] == 0)
				for (int next : map[b]) degree[next]++;
		}
	}

	if (ans)
		printf("King-God-Emperor");
	else
		printf("Lier!");

	return 0;
}
