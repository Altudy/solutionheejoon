#include <iostream>
using namespace std;

int main()
{
	int num, ans;
	cin >> num;
	ans = num % 8;

	switch(ans) {
	case 0: cout << "2"; break;
	case 1: cout << "1"; break;
	case 2: cout << "2"; break;
	case 3: cout << "3"; break;
	case 4: cout << "4"; break;
	case 5: cout << "5"; break;
	case 6: cout << "4"; break;
	case 7: cout << "3"; break;
	}
	return 0;
}