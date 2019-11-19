#include <iostream>	// 백준 2869
using namespace std;
int main()
{
	int A, B, V, day(0);
	cin >> A >> B >> V;
	V -= A;
	day++;
	if (V <= 0) {
		cout << day;
		return 0;
	}
	if (V % (A - B) == 0) {
		V = V / (A - B);
		day = day + V;
	}
	else {
	V = V / (A - B);
	day = day + V + 1;
	}
	cout << day;
	return 0;
}
