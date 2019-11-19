#include <iostream>	// 백준 1037
#include <algorithm>
using namespace std;

int main()
{
	int num, a, aMax(0), aMin(1000000);

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		aMax = max(aMax, a);
		aMin = min(aMin, a);
	}
	cout << aMax * aMin;
	return 0;
}
