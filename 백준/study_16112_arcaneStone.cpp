#include <iostream>		//백준 16112
#include <algorithm>
using namespace std;

void input();
int n, k;
long long int arr[300001];
long long int ex(0);

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	input();

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		ex += min(i, k) * arr[i];
	}
	cout << ex;

	return 0;
}

void input()
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
