#include <iostream> // 백준 17127
#include <algorithm>
using namespace std;

int mul(int start, int fin, int array[]);
int sakura;

int main()
{
	int ans(0);
	cin >> sakura;
	int* flower = new int[sakura];
	for (int i = 0; i < sakura; i++) {
		cin >> flower[i];
	}

	for (int i = 0; i < sakura - 3; i++) {
		for (int j = i+1; j < sakura - 2; j++) {
			for (int k = j+1; k < sakura-1; k++) {
				ans = max(ans, mul(0, i, flower) + mul(i+1, j, flower) +	mul(j+1, k, flower) + mul(k+1, sakura, flower));
			}
		}
	}
	cout << ans;
	return 0;
}

int mul(int start, int fin, int array[]) {
	int mul(1);
	for (int i = start; i <= fin; i++) {
		if (i >= sakura)	return mul;
		mul *= array[i];
	}
	return mul;
}