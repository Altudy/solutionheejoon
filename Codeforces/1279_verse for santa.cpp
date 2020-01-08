#include <iostream>		//CF1279

using namespace std;

void input();
int n, s, temp, m(0), ans(0);
long long sum(0);
int arr[100001]{};

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while(t--)
	{
		cin >> n >> s;
		temp = s;
		
		input();

		int i = 0;
		m = 0;

		if (sum <= s) cout << "0" << endl;
		else
		{
			while (temp >= 0 && i <= n-1)
			{
				temp -= arr[i];
				if (m < arr[i])
				{
					ans = i + 1;
					m = arr[i];
				}
				i++;
				cout << "ans : " << ans;
				cout << " temp : " << temp << endl;
 			}
			if (temp + m < 0) cout << "0" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}

void input()
{
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
}
