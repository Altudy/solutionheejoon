// top down
#include <iostream>		// 백준 1932
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	int floor;
	cin >> floor;

	vector<vector<int>> tri;
	tri.assign(floor, vector<int>(floor, 0));	// 2차원 벡터

	vector<vector<int>> map;
	map.assign(floor, vector<int>(floor, 0));	// 2차원 벡터

	for (int i = 0; i < floor; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> tri[i][j];					// 삼각형 입력받음
	map = tri;
	for (int i=0; i<floor-1; i++)
		for (int j = 0; j < i + 1; j++) {
			map[i + 1][j] = max(map[i][j] + tri[i + 1][j], map[i + 1][j]);
			map[i + 1][j + 1] = max(map[i][j] + tri[i + 1][j + 1], map[i + 1][j + 1]);
		}

	int ans(0);

	for (int i = 0; i < floor; i++) {
		ans = max(ans,map[floor - 1][i]);
	}

	cout << ans;

	return 0;
}


/*
// bottom up
#include <iostream>		// 백준 1932
#include <algorithm>
using namespace std;

int main()
{
	int floor;
	cin >> floor;						// 층 수 입력받음
	int** triangle = new int* [floor];
	for (int i = 0; i < floor; i++)
		triangle[i] = new int[floor];	// 2차원 배열 동적할당

	for (int i = floor-1; i >= 0; i--)
		for (int j = 0; j < floor-i; j++)
			cin >> triangle[i][j];
										// 삼각형 입력받음

	for (int i = 1; i < floor; i++)
		for (int j = 0; j < floor-i; j++)
			triangle[i][j] = max(triangle[i][j] + triangle[i - 1][j], triangle[i][j] + triangle[i - 1][j + 1]);

	cout << triangle[floor - 1][0];
	return 0;
}
*/
