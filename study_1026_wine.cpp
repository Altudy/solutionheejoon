#include <iostream>		// 백준 2156
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* wine = new int[n+1];
	int* drink = new int[n+1];
	int* last = new int[n+1] {};

	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	drink[0] = 0;
	drink[1] = wine[1];
	drink[2] = wine[1] + wine[2];
	last[2] = 2;

	int i(3);

	while (i <= n) {
		if (last[i-1] != 2) {
			drink[i] = drink[i - 1] + wine[i];
		}
		else {
			drink[i] = max(drink[i - 1], drink[i - 2] + wine[i]);
			drink[i] = max(drink[i], drink[i - 3] + wine[i] + wine[i - 1]);
		}

		if (drink[i] == drink[i - 3] + wine[i] + wine[i - 1]) {
			last[i] = 2;
		}

		i++;
	}

	cout << drink[n];
	return 0;
}


// n : wine 잔의 수
// wine[] : k번 째 wine 양
// drink[] : k개까지 마실 수 있는 최대
// last[] : 마지막에 마신 와인 잔 수 0~2

// last[k] = 0	=>	drink[n] = drink[n-1]
//			 0	=>	drink[n]-wine[n] = drink[n-2]
//			 2	=>	drink[n]-wine[n-1]-wine[n-2] = drink[n-3]

// last[]=0,1이면 drink[n]=drink[n-1]+wine[n]
// last[] = 2 일 때
// drink[n] = max( drink[n-1],
//					drink[n-2]+wine[n],
//					drink[n-3]+wine[n]+wine[n-1])