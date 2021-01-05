#include <iostream>		// 백준 10942

using namespace std;

int n;
int arr[2000];
int t, x, y;
bool chk[2000][2000]{};
// true:펠린드롬, false:아니다

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	cin >> t;
}

void dp()
{
	for (int i = 0; i < n; i++)
	{
		chk[i][i] = 1;	//길이가 1일 때
		for (int j = 1; j < n; j++)
		{
			if (i - j < 0 || i + j >= n) break;
			if (arr[i - j] == arr[i + j]) chk[i - j][i + j] = true;
			else break;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == arr[i])
		{
			chk[i - 1][i] = true;	// 길이가 2일 때 정해줌
			for (int j = 1; j < n; j++)
			{
				if (i - 1 - j < 0 || i + j >= n) break;
				if (arr[i - 1 - j] == arr[i + j]) chk[i - 1 - j][i + j] = true;
				else break;
			}
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);

	input();
	dp();

	while (t--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", chk[x - 1][y - 1]);
	}
	return 0;
}
