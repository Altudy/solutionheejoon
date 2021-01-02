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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	map<string, bool> stack;
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		stack[str] = true;
	}

	string T = "!";
	bool sat = true;
	for (auto s : stack)
	{
		if (s.first[0] != '!') {
			T += s.first;
			if (stack.find(T) != stack.end()) {
				cout << s.first; sat = false; break;
			}
			T = "!";
		}
	}

	if (sat) cout << "satisfiable";

	return 0;
}
