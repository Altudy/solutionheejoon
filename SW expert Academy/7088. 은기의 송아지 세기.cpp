#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << endl;
		int N, Q, num;
		cin >> N >> Q;

		vector<vector<int>> cows(N+1, vector<int>(3));

		for (int i = 1; i <= N; i++)
		{
			cin >> num;
			cows[i] = cows[i - 1];
			cows[i][num - 1]++;
		}

		int ll, rr;
		for (int i = 1; i <= Q; i++)
		{
			cin >> ll >> rr;

			cout << cows[rr][0] - cows[ll-1][0] << " ";
			cout << cows[rr][1] - cows[ll-1][1] << " ";
			cout << cows[rr][2] - cows[ll-1][2] << " \n";
		}
	}
	return 0;
}
