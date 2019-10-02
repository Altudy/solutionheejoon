#include <iostream>
using namespace std;

int add(int num);

int main()
{
	int t;
	cin >> t;
	int* num = new int[t];
	for (int i = 0; i < t; i++)
		cin >> num[i];

	for (int i = 0; i < t; i++) {
		int ans = add(num[i]);
		cout << ans<< endl;
	}
	return 0;
}

int add(int num) {
	int ans;
	switch (num) {
	case 1 : return 1;
	case 2 : return 2;
	case 3 : return 4;
	default :
			ans = add(num - 1) + add(num - 2) + add(num - 3);
			return ans;
	}
}

/*
	테스트 케이스 개수 T
	정수 n
	n을 1,2,3의 합으로 나타내는 방법
	add(n) = add(n-1) + add(n-2) + add(n-3)
*/