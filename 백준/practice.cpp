#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	int three(0), five(0);

	cin >> n;

	while (1)
	{
		if (n % 5 == 0) break;
		n -= 3;
		three++;
	}

	if (n < 0) {
		cout << "-1";
		return 0;
	}

	five = n / 5;
	cout << three + five;

	return 0;
}