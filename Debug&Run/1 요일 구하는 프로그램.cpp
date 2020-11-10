#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int dates[13]{};
	dates[1] = 31;
	dates[2] = 28;
	dates[3] = 31;
	dates[4] = 30;
	dates[5] = 31;
	dates[6] = 30;
	dates[7] = 31;
	dates[8] = 31;
	dates[9] = 30;
	dates[10] = 31;
	dates[11] = 30;
	dates[12] = 31;

	int sum(0);
	int year, month, day;
	cin >> year >> month >> day;

	if (year < 1900 || month <= 0 || month>12 || day <= 0 || day > 31) {
		cout << "ERR"; return 0;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		cout << "ERR"; return 0;
	}

	for(int i=1900; i<year; i++)
	{
		if (isLeapYear(i)) sum += 366;
		else sum += 365;
	}

	for (int i = 1; i < month; i++) sum += dates[i];
	if (isLeapYear(year) && month > 2) sum++;
	sum += day;
	
	if (sum % 7 == 0) cout << "SUN";
	else if (sum % 7 == 1) cout << "MON";
	else if (sum % 7 == 2) cout << "TUE";
	else if (sum % 7 == 3) cout << "WED";
	else if (sum % 7 == 4) cout << "THU";
	else if (sum % 7 == 5) cout << "FRI";
	else if (sum % 7 == 6) cout << "SAT";


	return 0;
}
