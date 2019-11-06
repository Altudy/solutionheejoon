#include <iostream>		// 백준 1931
#include <algorithm>
using namespace std;

struct timetable {
	int begin, end;
};

bool comp(const timetable& a, const timetable& b) {
	if (a.end == b.end)
		return a.begin < b.begin;		// 종료시간이 같다면, 시작시간 순
	else
		return a.end < b.end;			// 종료시간이 다르면, 종료시간 순
}

int main()
{
	timetable m[100000];
	int n, cnt(0), last(0), x(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> m[i].begin >> m[i].end;

	sort(m, m+n, comp);
	
	for (int i = 0; i < n; i++)
	{
		if (last <= m[i].begin) {
			last = m[i].end;
			cnt++;
		}
	}
	cout << cnt;;
	return 0;
}