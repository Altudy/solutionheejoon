#include <iostream>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int t;
	int a, b, c, n;
	int s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c >> n;
		s = a + b + c + n;
		if (a > s / 3 || b > s / 3 || c > s / 3) cout << "NO" << endl;
		else if (s % 3 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
 
	}
	return 0;
}
