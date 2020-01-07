#include <iostream>		// 백준 1463
#include <algorithm>
using namespace std;
int n;
int one[1000001];

int main()
{
	cin >> n;
	one[1] = 0;
	for (int i = 2; i <= n; i++) {
		one[i] = one[i - 1] + 1;
		if (i % 3 == 0) one[i] = min(one[i], one[i / 3] + 1);
		if (i % 2 == 0) one[i] = min(one[i], one[i / 2] + 1);
	}
	cout << one[n];
	return 0;
}
/*
	정수 x
	1. 3으로 나눈다.
	2. 2로 나눈다.
	3. 1을 뺀다.

1			0
2 1			1
3 1			1
4 3 1		2
5 4			3
6 3			2
7 6			3
8 4			3
9 3			2
10 9		3
11 10		4
12 4		3
13 12		4
14 7		4
15 5		4 
16 8		4
17 16		5

33 11		5
33 32 16	6
*/
