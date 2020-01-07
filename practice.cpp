#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string s;
	int dir(0), n, p, c;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		dir = 0;		//처음부터 살피기
		n = 0;			//북서가 몇개 째인지
		p = 0;			//분자 0부터
		cin >> s;

		while (dir < s.length())
		{
			if (s[dir] == 'n')
			{
				dir += 5;
				if (dir != s.length()) p -= pow(2, n);
			}
			else
			{
				dir += 4;
				p += pow(2, n);
			}
			n++;
		}
		c = pow(2, n - 2);

		p = p * 45;

		if (c == 0 && p == 45) cout << "#" << test_case << " 90" << endl;
		else if (c == 0 && p == 0) cout << "#" << test_case << " 0" << endl;
		else if (c == 1 && p == 45) cout << "#" << test_case << " 45" << endl;
		else if (c == 1 && p == 315) cout << "#" << test_case << " 45" << endl;
		else cout << "#" << test_case << " " << p << "/" << c << endl;
	}
	return 0;
}