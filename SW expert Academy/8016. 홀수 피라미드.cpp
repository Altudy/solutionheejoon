#include<iostream>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	long long int k;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> k;
		cout << "#" << test_case << " " << 2 * (k-1) * (k-1) + 1 << " " << 2 * k * k - 1 << endl;
	}
	return 0;
}
