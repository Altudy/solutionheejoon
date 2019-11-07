#include <iostream>		// 백준 2661
using namespace std;

int n, sq[81];
bool fin=false;

void bt(int idx, int num);
bool promising(int idx);

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	sq[0] = 1;
	bt(1, 2);

	return 0;
}

void bt(int idx, int num)
{
	sq[idx] = num;
	if (promising(idx))
	{
		if (fin) return;
		if (idx == n) {
			for (int i = 0; i < n; i++) cout << sq[i];
			fin=true;
		}
		bt(idx + 1, 1);
		bt(idx + 1, 2);
		bt(idx + 1, 3);
	}
}
bool promising(int idx)
{
	if (sq[idx] == sq[idx - 1]) return false;
	for (int i = 2; i <= n / 2; i++)
	{
		int j(1);
		if (sq[idx] != sq[idx - i]) continue;
		while (j < i)
		{
			if (sq[idx-j]!=sq[idx-i-j]) break;
			j++;
			if (i == j) return false;
		}
	}
	return true;
}

/*
	i : idx에서 차이나는 index 수
	j : idx와 i사이의 index
*/