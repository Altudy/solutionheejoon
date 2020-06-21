#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

int dp[10001];

void solve() {
	int h, n;
	cin >> h >> n;
	
	fill(dp, dp + h + 1, mod);
	dp[0] = 0;

	rep(i, n) {
		int a, b;
		cin >> a >> b;

		rep(j, h) {
			dp[min(j + a, h)] = min(dp[min(j + a, h)], dp[j] + b);
		}
	}
	cout << dp[h] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}
