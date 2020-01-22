#include <iostream>       //백준 2579
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> stair;
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		stair.push_back(temp);
	}

	ans.assign(n, 0);
	ans[0] = stair[0];
	ans[1] = ans[0] + stair[1];
	ans[2] = max(ans[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++)
		ans[i] = max(ans[i - 2] + stair[i], ans[i - 3] + stair[i] + stair[i - 1]);

	cout << ans[n - 1];

	return 0;
}
