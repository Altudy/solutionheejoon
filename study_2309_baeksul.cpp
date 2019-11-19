#include <iostream>	// 백준 2309
#include <algorithm>
using namespace std;
int main()
{
	int tall[9], sum(0);
	for (int i = 0; i < 9; i++)
	{
		cin >> tall[i];
		sum += tall[i];
	}
	for (int i = 0; i < 8; i++)
	{
		for(int j = i+1; j < 9 ; j++)
		{
			if (sum - tall[i] - tall[j] == 100)
			{
				tall[i]=0;
				tall[j]=0;
				sort(tall, tall + 9);
				cout << tall[2] << endl << tall[3] << endl << tall[4] << endl << tall[5] << endl << tall[6] << endl << tall[7] << endl << tall[8];
				return 0;
			}
		}
	}
	return 0;
}
