#include<iostream>

using namespace std;
typedef long long int ll;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int T;
	cin >> T;
	ll n, a, b;
    ll ans;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> a >> b;
        ans = (a + b * (n-1)) - (a * (n-1) + b) + 1;
		if (ans < 0 || a > b) cout << "#" << test_case << " " << 0 << "\n";
        else cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
