#include <iostream>
using namespace std;
 
typedef long long int ll;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int T;
	cin >> T;
 
	ll ans(0);
	while (T--)
	{
		int n;
		cin >> n;
		for (ll i = 0; i <= n/2; i++)
			ans += 8 * i * i;
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
