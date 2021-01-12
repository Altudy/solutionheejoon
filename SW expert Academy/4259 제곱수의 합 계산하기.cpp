#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;

vector<int> temp;
vector<int> sum;

void solution(int num)
{
	int a, expo;
	a = num / 10;
	expo = num % 10;
	temp[0] = 1;

	for (int i = 0; i < expo; i++)
	{
		for (int j = 0; j < 30; j++) temp[j] *= a;
		for (int j = 0; j < 30; j++) {
			temp[j + 1] += temp[j] / 10;
			temp[j] %= 10;
		}
	}

	for (int i = 0; i < 30; i++) {
		sum[i] += temp[i];
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, num;
		cin >> n;

		sum.assign(31, 0);
		for (int i = 0; i < n; i++)
		{
			temp.assign(31, 0);
			cin >> num;
			solution(num);
		}

		bool chk = false;
		cout << "\n#" << test_case << " ";
		for (int i = 30; i >= 0; i--) {
			cout << sum[i];
			if (sum[i]) chk = true;
			if (chk) cout << sum[i];
		}
		cout << "\n\n";
	}
	return 0;
}
