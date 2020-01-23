#include <iostream>   // 백준 1261
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int row, col;
int map[100][100]{};
queue <pii> p;
int dist[100][100]{};

void init()
{
	cin >> col >> row;
	char temp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			if (temp == '1') map[i][j] = 1;
		}
	}
	p.push({ 0,0 });
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dist[i][j] = 1000;
	dist[0][0] = 0;
}

void sol()
{
	pii a;

	while (!p.empty())
	{
		a = p.front(); p.pop();
		//up
		if (a.first - 1 >= 0 && dist[a.first - 1][a.second] > dist[a.first][a.second] + map[a.first - 1][a.second])
		{
			p.push({ a.first - 1, a.second });
			dist[a.first - 1][a.second] = dist[a.first][a.second] + map[a.first - 1][a.second];
		}
		//down
		if (a.first + 1 < row && dist[a.first + 1][a.second] > dist[a.first][a.second] + map[a.first + 1][a.second])
		{
			p.push({ a.first + 1, a.second });
			dist[a.first + 1][a.second] = dist[a.first][a.second] + map[a.first + 1][a.second];
		}
		//left
		if (a.second - 1 >= 0 && dist[a.first][a.second - 1] > dist[a.first][a.second] + map[a.first][a.second - 1])
		{
			p.push({ a.first, a.second - 1 });
			dist[a.first][a.second - 1] = dist[a.first][a.second] + map[a.first][a.second - 1];
		}
		//right
		if (a.second + 1 < col && dist[a.first][a.second + 1] > dist[a.first][a.second] + map[a.first][a.second + 1])
		{
			p.push({ a.first, a.second + 1 });
			dist[a.first][a.second + 1] = dist[a.first][a.second] + map[a.first][a.second + 1];
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	sol();

	cout << dist[row - 1][col - 1];

	return 0;
}
