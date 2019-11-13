#include <iostream>			// 백준 1713
using namespace std;

struct student
{
	int recommend;			// 학생의 추천 수
	int order;				// 학생이 추천 받은 순서.
};

int i, frame, total;

int main()
{
	ios::sync_with_stdio(false);

	cin >> frame;			// 사진틀의 개수
	cin >> total;			// 전체 추천 수

	student student[101] = { 0, };

	while (frame > 0 && total > 0)
	{
		cin >> i;
		if (student[i].recommend == 0)
		{
			frame--;
			student[i].order = total;		// 시간은 전체 추천수에서 하나씩 줄어들면서 지나는 걸로.
		}
		student[i].recommend++;
		total--;
	}

	while (total > 0)
	{
		cin >> i;
		if (student[i].recommend != 0)
		{
			student[i].recommend++;
			total--;
			continue;
		}
		
		student[i].recommend++;
		student[i].order = total;
		total--;

		int del_rec = 1000;
		int del_ord = 0;
		int del=0;

		for (int k = 1; k <= 100; k++)			// 삭제할 놈 찾기.
		{
			if (0 < student[k].recommend && student[k].recommend < del_rec)		// 추천수가 제일 작은 놈.
			{
				del_rec = student[k].recommend;
				del_ord = student[k].order;
				del = k;
			}
			else if (student[k].recommend == del_rec && student[k].order > del_ord)	// 추천수가 제일 작은 놈 중 오래된놈.
			{
				del_rec = student[k].recommend;
				del_ord = student[k].order;
				del = k;
			}
		}
		student[del].recommend = 0;
	}

	for (int k = 1; k <= 100; k++)
	{
		if (student[k].recommend > 0)
			cout << k << " ";
	}
	return 0;
}

/*
	for (int k = 1; k <= 10; k++)
	{
		cout << k << "\t" << student[k].recommend << "\t" << student[k].order << endl;
	}

*/