#include <iostream>		// 백준 2163
#include <algorithm>
#include <limits.h>
using namespace std;

void dp(int x, int y);
void initial();		
void switching(int& a, int& b);
int** mat;
int N, M;			// N x M 초콜릿

int main()
{
	ios::sync_with_stdio(false);
	initial();		// 초기 환경
	dp(2, 2);		// 계산
	return 0;
}

void initial()
{
	cin >> N >> M;
	int k = max(N, M);
	if(M < N) switching(N, M);

	mat = new int* [k + 1];
	for (int i = 0; i <= k; i++)
		mat[i] = new int[k + 1]{};

	for (int i = 0; i < k; i++)
	{
		mat[1][i+1] = i;
		mat[i+1][1] = i;
	}
}

void dp(int x, int y)
{
	if (x > y) switching(x, y);
//	cout << "x : " << x << "\ty : " << y << endl;
	if (x > N) {
//		cout << "x : " << x << "\tN : " << N << endl;
 		cout << mat[N][M];
		exit(0);
	}
	if (y > M) {
//		cout << "y : " << y << "\tM : " << M << endl;
		dp(x + 1, x + 1);
		return;
	}
	int m = INT_MAX;
	   
	for (int i = 1; i <= y / 2; i++)
	{
		m = min(mat[x][y - i] + mat[x][i] + 1, m);
	}
	if (x != y)
	{
		for (int j = 1; j <= x / 2; j++)
		{
			m = min(mat[x - j][y] + mat[j][y] + 1, m);
		}
		mat[y][x] = m;
	}
//	cout << "m : " << m << endl;
	mat[x][y] = m;

	dp(x, y + 1);
}

void switching(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


#include<iostream>

using namespace std;

int main() {

	int x, y;

	cin >> x >> y;

	cout << x * y - 1 << endl;

}
