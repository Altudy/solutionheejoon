#include <iostream>		//백준 9519
#include <string>
using namespace std;

int main()
{
	int blink;
	string word;
	cin >> blink >> word;

	string ans = word;
	string temp = word;
	int cnt = 0;

	for (int k = 0; k < blink; k++)
	{
		for (int i = 0; i < word.length(); i += 2)
		{
			ans[i / 2] = word[i];
			ans[word.length() - i / 2 - 1] = word[i + 1];
		}
		if (word.length() % 2 == 1)
		{
			ans[word.length() / 2] = word[word.length() - 1];
		}
		word = ans;
		cnt++;
		if (temp == ans) break;
	}

	blink %= cnt;	//패턴만큼 나누어서 반복을 줄인다.

	for (int k = 0; k < blink; k++)
	{
		for (int i = 0; i < word.length(); i += 2)
		{
			ans[i / 2] = word[i];
			ans[word.length() - i / 2 - 1] = word[i + 1];
		}
		if (word.length() % 2 == 1)
		{
			ans[word.length() / 2] = word[word.length() - 1];
		}
		word = ans;
	}

	cout << ans;
	return 0;
}