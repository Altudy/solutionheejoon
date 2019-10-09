#include <iostream>		// 백준 1463
#define MAX 1000000
using namespace std;
int d[1000001] = {};
int x;

void one(int i);

int main() {
		d[1] = 0;
		cin >> x;

		one(1);
		cout << d[x];
		return 0;
}

void one(int i) {
	if (i > x) return;
	if (i + 1 > MAX) return;
	if (d[i + 1] == 0) d[i + 1] = d[i] + 1;
	if (i * 2 > MAX) return;
	if (d[i * 2] == 0) d[i * 2] = d[i] + 1;
	if (i * 3 > MAX) return;
	if (d[i * 3] == 0) d[i * 3] = d[i] + 1;
	one(i * 3);
	one(i * 2);
	one(i + 1);
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