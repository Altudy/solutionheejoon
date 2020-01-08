#include <iostream>   //CF 455 A
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
ll arr[100001]{};
ll sum[100001]{};
int n;
 
int main()
{
	ios::sync_with_stdio(false);
 
	cin >> n;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[temp] += temp;
	}
 
	sum[1] = arr[1];
 
	for (int i = 2; i <= 100000; i++)
	{
		sum[i] = max(sum[i - 1], sum[i - 2] + arr[i]);
	}
	cout << sum[100000];
 
	return 0;
}
