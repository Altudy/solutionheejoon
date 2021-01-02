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

typedef pair<float, float> pii;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, ans;
	float x, y, a;
	cin >> N;

	vector<pii> point;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		point.push_back({ x,y });
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			a = abs((point[i].second - point[j].second) / (point[i].first - point[j].first));
			if (a <= 1) ans++;
		}
	}
	cout << ans;

	return 0;
}
