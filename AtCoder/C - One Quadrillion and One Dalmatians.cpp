#include <iostream>

using namespace std;

typedef long long int ll;

void func(ll n)
{
	if (n == 0) return;
	n--;
	func(n / 26);
	cout << char('a' + n % 26);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll num;
	cin >> num;
	func(num);
	return 0;
}
