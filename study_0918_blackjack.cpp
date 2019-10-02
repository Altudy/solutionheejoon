#include <iostream>
using namespace std;
int main()
{
	int N, M, card[100] = {};
	cin >> N >> M;
		for (int i = 0; i < N; i++)
		cin >> card[i];
	int max = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (((card[i] + card[j] + card[k]) > max) && ((card[i] + card[j] + card[k]) <= M))
					max = card[i] + card[j] + card[k];
			}
		}
	}
	cout << max << endl;
	return 0;
}