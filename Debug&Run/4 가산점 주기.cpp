#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> v;
	int sum(0);
	for (int i = 0; i < 13; i++) {
		v.push_back(getchar() - 48);
		sum += v[i];
	}

	// chk id error
	sum -= v[12];
	if (sum % 10 != v[12])
	{
		cout << "I-ERR"; return 0;
	}

	// get birthday
	int year, month, day;
	if (v[6] == 1 || v[6] == 2) {
		year = 1900 + v[0] * 10 + v[1];
	}
	else {
		year = 2000 + v[0] * 10 + v[1];
	}
	month = v[2] * 10 + v[3];
	day = v[4] * 10 + v[5];

	// chk date error
	if (year < 1900 || month <= 0 || month>12 || day <= 0 || day > 31) {
		cout << "ERR"; return 0;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		cout << "ERR"; return 0;
	}

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				if (month == 2 && day > 29) {
					cout << "D-ERR"; return 0;
				}
			}
			else
				if (month == 2 && day > 28) {
					cout << "D-ERR"; return 0;
				}
		}
		else {
			if (month == 2 && day > 29) {
				cout << "D-ERR"; return 0;
			}
		}
	}
	else
		if (month == 2 && day > 28) {
			cout << "D-ERR"; return 0;
		}

	cout << "VALID";

	return 0;
}
