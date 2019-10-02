#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int game[18] = {}, result[4] = {};
	for (int i = 0; i < 4; i++) {
		int win(0), draw(0), lose(0), team(0);
		int winMax(0), winNum(0), drawMax(0), drawNum(0), loseMax(0), loseNum(0);

		for (int j = 0; j < 18; j++) {
			cin >> game[j];
			if (j % 3 == 0) {					// win
				win += game[j];
				team += game[j];
				winMax = max(winMax, game[j]);
				if (game[j] != 0)
					winNum++;
			}
			else if (j % 3 == 1) {				// draw
				draw += game[j];
				team += game[j];
				drawMax = max(drawMax, game[j]);
				if (game[j] != 0)
					drawNum++;
			}
			else if (j % 3 == 2) {				// loss
				lose += game[j];
				team += game[j];
				loseMax = max(loseMax, game[j]);
				if (game[j] != 0)
					loseNum++;
				if (team % 5 != 0) {
					result[i] = 0;
					j = 18;			
				}
			}
		}
		if (win != lose || draw % 2 != 0 ||
			drawMax>drawNum || winMax>loseNum || loseMax>winNum) {
			result[i] = 0;
		}
		else
			result[i] = 1;
	}
	for (int i = 0; i < 4; i++) {
		cout << result[i] << " ";
	}
	return 0;
}

/*
	0 <= 승, 무, 패 <=6
	가능 : 1 / 불가능 : 0
*/