#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	char a;
	cin >> a;

	if (a > 96)
		cout << 'a';
	else
		cout << 'A';

	return 0;
}
