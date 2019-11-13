#include <iostream>		// 백준 2580
using namespace std;

int map[10][10];
bool chk_row[10][10]{};
bool chk_col[10][10]{};
bool chk_box[10][10]{};

void play(int round)
{
	if (round == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}				// 탈출조건

	int row = round / 9;
	int col = round % 9;

	if(map[row][col] != 0) play(round + 1);
	else {
		for (int i = 1; i <= 9; i++)
		{
			if (!chk_row[row][i] && !chk_col[col][i] && !chk_box[(row / 3) * 3 + col / 3][i])
			{
				map[row][col] = i;
				chk_row[row][i] = true;
				chk_col[col][i] = true;
				chk_box[(row / 3) * 3 + col / 3][i] = true;
				play(round + 1);
				map[row][col] = 0;
				chk_row[row][i] = false;
				chk_col[col][i] = false;
				chk_box[(row / 3) * 3 + col / 3][i] = false;
			}
		}
	}


}

int main()
{
	ios::sync_with_stdio(false);
	for(int i=0; i<9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0) {
				chk_row[i][map[i][j]] = true;		// 해당 숫자가 들어가 있으면 true
				chk_col[j][map[i][j]] = true;
				chk_box[(i / 3) * 3 + j / 3][map[i][j]] = true;
			}
		}
	play(0);
	return 0;
}
