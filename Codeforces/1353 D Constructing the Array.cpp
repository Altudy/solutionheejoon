#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct group {
	group(int s, int e, int g) : start(s), end(e), gap(g) {}
	int start;
	int end;
	int gap;
};
 
struct cmp{
	bool operator()(group a, group b) {
		if (a.gap == b.gap)
			return a.start > b.start; // 작은놈이 앞에 나옴
		return a.gap < b.gap; // 큰놈이 앞에 나옴
	}
};
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int T;
	cin >> T;
 
	int n;
	priority_queue<group, vector<group>, cmp> pq;
 
	while (T--)
	{
		cin >> n;
		group x(1, n, n - 1);
		group y(1, n, n - 1);
		vector<int> v(n+1);
		pq.push(x);
		int mid;
 
		for (int i = 1; i <= n; i++)
		{
			y = pq.top(); pq.pop();
			if (y.gap == 0)
			{
				v[y.start] = i;
				continue;
			}
			if (y.gap == 1)
			{
				v[y.start] = i;
				x.start = y.end;
				x.end = y.end;
				x.gap = 0;
				pq.push(x);
				continue;
			}
 
			if (i % 2 == 0)
			{
				v[(y.start + y.end) / 2] = i;
				mid = (y.start + y.end) / 2;
			}
			else
			{
				v[(y.start + y.end) / 2] = i;
				mid = (y.start + y.end) / 2;
			}
      
			x.start = y.start;
			x.end = mid - 1;
			x.gap = x.end - x.start;
			pq.push(x);
			x.start = mid + 1;
			x.end = y.end;
			x.gap = x.end - x.start;
			pq.push(x);
		}
		for (int i = 1; i <= n; i++)
			cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
