#include <iostream>		// 백준 6603
using namespace std;

int num;
int lotto[12];
int result[6];
void choose(int idx1, int idx2);

int main()
{
	while (1) {
		cin >> num;
		if (num == 0) break;
		for (int i = 0; i < num; i++) {
			cin >> lotto[i];
		}

		choose(0, 0);
		cout << endl;
	}
	return 0;
}

void choose(int idx1, int idx2) {
	if (idx2==6) {
		for (int i = 0; i < 6; i++){
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx1; i < num; i++) {
		result[idx2]=lotto[i];
		choose(i + 1, idx2+1);
	}
}






/*
#include <iostream>
using namespace std;

int num;
int lotto[12];

int main()
{
	while (1) {
		cin >> num;					// 주어질 수의 갯수
		if (num == 0) break;
		for (int i = 0; i < num; i++) {
			cin >> lotto[i];		// lotto[]에 수 입력받기
		}
		for (int a = 0; a < num - 5; a++) {
			for (int b = a + 1; b < num - 4; b++) {
				for (int c = b + 1; c < num - 3; c++) {
					for (int d = c + 1; d < num - 2; d++) {
						for (int e = d + 1; e < num - 1; e++) {
							for (int f = e + 1; f < num; f++) {
								cout << lotto[a] << " " << lotto[b] << " " << lotto[c] << " "
									<< lotto[d] << " " << lotto[e] << " " << lotto[f] << endl;
							}
						}
					}
				}
			}
		}
	cout << endl;

	}
	return 0;
}
*/