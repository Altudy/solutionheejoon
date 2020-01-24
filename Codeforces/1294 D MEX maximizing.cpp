#include <iostream>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int q, x;
 
	cin >> q >> x;
 
	int num;
	int* a = new int[x] {};
	int line(0);
	int ans(0);
	while (q--)
	{
		cin >> num;
		a[num % x]++;
		
		for (int i = ans; i < x; i++)
		{
			if (a[i] <= line) break;
			ans++;
			if (i == x - 1)
			{
				ans = 0;
				line++;
				i = -1;
			}
		}
		cout << line*x + ans << endl;
	}
	return 0;
}
