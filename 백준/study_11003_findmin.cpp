#include <iostream>		// 백준 11003
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int N, L;
vector<int> v;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void sol();
void out();

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> L;
	sol();
	out();

	return 0;
}

void sol()
{
	pii temp;
	int min(100000000);

	for (int i = 1; i <= N; i++)
	{
		cin >> temp.first;
		temp.second = i;

		pq.push(temp);
		while (pq.top().second <= (i - L))
		{
			pq.pop();
		}
		v.push_back(pq.top().first);
	}
}

void out()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
