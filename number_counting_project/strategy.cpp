#include <iostream>
#include <vector>
#include <math.h>
#include "strategy.h"
using namespace std;

strategy::strategy() : target_num(0), target(NULL), rcv_num(0), snd_num(0), added(0), gap(0), chance(false) {}
// constructor
// 모든 값을 0으로 만든다.

void strategy::readTarget(int num, int* ptrTarget)
{
	target = new int[num];
	target_num = num;
	for (int i = 0; i < num; i++)
	{
		target[i] = ptrTarget[i];
	}
	if (target_num > 1)
	{
		gap = target[1] - target[0];
	}
}

void strategy::map_first()
{
	if (gap >= 5)
	{
		for (int k = 0; k < target_num; k++)
		{
			if (k == 0)			// 일부러 지기 위해 질 수 있는 점수에 weight를 준다.
			{
				int k = 0;
				int weight = pow(10, target_num - k - 1);       // 가까운 target을 위한 가중치
				for (int i = target[k] - 5; i < 100; i++)		// 첫 target 이후에도 wieght를 주는 이유는
																// target 이후의 가중치가 더 낮을 수 도 있어 지지 않을 때가 발생
					for (int j = 1; j <= 5; j++)
						win[k][i][j] = weight;        // target 포함 아래 5개의 점수를 weight로 초기화
				for (int j = 1; j <= 5; j++)
					win[k][target[k] - 1][j] = 0;
				win[k][target[k] - 4][1] = 0;
				win[k][target[k] - 4][5] = 0;
				win[k][target[k] - 3][4] = 0;
				win[k][target[k] - 3][5] = 0;
				win[k][target[k] - 2][3] = 0;
				win[k][target[k] - 2][4] = 0;
				win[k][target[k] - 2][5] = 0;		 // target 을 획득할 수는 빼준다.
				for (int i = target[k] - 6; i > 0; i--)   // 점수를 딸 수 있는 자리에 weight를 넣어준다.
				{
					if (win[k][i + 1][1] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; }
					if (win[k][i + 2][2] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; win[k][i][3] = weight; }
					if (win[k][i + 3][3] == 0) { win[k][i][2] = weight; win[k][i][3] = weight; win[k][i][4] = weight; }
					if (win[k][i + 4][4] == 0) { win[k][i][3] = weight; win[k][i][4] = weight; win[k][i][5] = weight; }
					if (win[k][i + 5][5] == 0) { win[k][i][4] = weight; win[k][i][5] = weight; }
				}

			}
			else
			{
				int weight = pow(10, target_num - k - 1);        // 가까운 target을 위한 가중치

				for (int i = target[k] - 5; i <= target[k] - 1; i++)
					for (int j = 1; j <= 5; j++)
						win[k][i][j] = weight;        // target 포함 아래 5개의 점수를 weight로 초기화

				win[k][target[k] - 5][1] = 0;
				win[k][target[k] - 5][2] = 0;
				win[k][target[k] - 5][3] = 0;
				win[k][target[k] - 3][1] = 0;       // target 을 획득하지 못할 수는 빼준다.

				for (int i = target[k] - 6; i > 0; i--)   // 점수를 딸 수 있는 자리에 weight를 넣어준다.
				{
					if (win[k][i + 1][1] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; }
					if (win[k][i + 2][2] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; win[k][i][3] = weight; }
					if (win[k][i + 3][3] == 0) { win[k][i][2] = weight; win[k][i][3] = weight; win[k][i][4] = weight; }
					if (win[k][i + 4][4] == 0) { win[k][i][3] = weight; win[k][i][4] = weight; win[k][i][5] = weight; }
					if (win[k][i + 5][5] == 0) { win[k][i][4] = weight; win[k][i][5] = weight; }
				}
			}
		}
	}
	else if (gap == 0) {		// 상대가 target을 하나만 보냈을 때
		map_second(); return;
	}
	else if (gap == 1 || gap == 2) map_one();
	else if (gap == 3) map_three();
	else if (gap == 4) map_four();
	sum();
}

void strategy::map_second()
{
	for (int k = 0; k < target_num; k++)
	{
		int weight = pow(10, target_num - k - 1);        // 가까운 target을 위한 가중치

		for (int i = target[k] - 5; i <= target[k] - 1; i++)
			for (int j = 1; j <= 5; j++)
				win[k][i][j] = weight;        // target 포함 아래 5개의 점수를 weight로 초기화

		win[k][target[k] - 5][1] = 0;
		win[k][target[k] - 5][2] = 0;
		win[k][target[k] - 5][3] = 0;
		win[k][target[k] - 3][1] = 0;       // target 을 획득하지 못할 수는 빼준다.

		for (int i = target[k] - 6; i > 0; i--)   // 점수를 딸 수 있는 자리에 weight를 넣어준다.
		{
			if (win[k][i + 1][1] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; }
			if (win[k][i + 2][2] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; win[k][i][3] = weight; }
			if (win[k][i + 3][3] == 0) { win[k][i][2] = weight; win[k][i][3] = weight; win[k][i][4] = weight; }
			if (win[k][i + 4][4] == 0) { win[k][i][3] = weight; win[k][i][4] = weight; win[k][i][5] = weight; }
			if (win[k][i + 5][5] == 0) { win[k][i][4] = weight; win[k][i][5] = weight; }
		}
	}
	sum();
}

void strategy::map_one()
{
	int k = 1;
	int weight = pow(10, target_num - k - 1);        // 가까운 target을 위한 가중치

	for (int i = target[k] - 5; i <= target[k] - 1; i++)
		for (int j = 1; j <= 5; j++)
			win[k][i][j] = weight;        // target 포함 아래 5개의 점수를 weight로 초기화

	win[k][target[k] - 5][1] = 0;
	win[k][target[k] - 5][2] = 0;
	win[k][target[k] - 5][3] = 0;
	win[k][target[k] - 3][1] = 0;       // target 을 획득하지 못할 수는 빼준다.

	for (int i = target[k] - 6; i > 0; i--)   // 점수를 딸 수 있는 자리에 weight를 넣어준다.
	{
		if (win[k][i + 1][1] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; }
		if (win[k][i + 2][2] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; win[k][i][3] = weight; }
		if (win[k][i + 3][3] == 0) { win[k][i][2] = weight; win[k][i][3] = weight; win[k][i][4] = weight; }
		if (win[k][i + 4][4] == 0) { win[k][i][3] = weight; win[k][i][4] = weight; win[k][i][5] = weight; }
		if (win[k][i + 5][5] == 0) { win[k][i][4] = weight; win[k][i][5] = weight; }
	}
}

void strategy::map_three()
{
	int k = 1;
	int weight = pow(10, target_num - k - 1);        // 가까운 target을 위한 가중치

	for (int i = target[k] - 5; i <= target[k] - 1; i++)
		for (int j = 1; j <= 5; j++)
			win[k][i][j] = weight;      // target 포함 아래 5개의 점수를 weight로 초기화

	win[k][target[k] - 4][1] = 0;
	win[k][target[k] - 4][2] = 0;
	win[k][target[k] - 5][3] = 0;		// target 을 획득하지 못할 수는 빼준다.

	for (int i = target[k] - 6; i > 0; i--)   // 점수를 딸 수 있는 자리에 weight를 넣어준다.
	{
		if (win[k][i + 1][1] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; }
		if (win[k][i + 2][2] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; win[k][i][3] = weight; }
		if (win[k][i + 3][3] == 0) { win[k][i][2] = weight; win[k][i][3] = weight; win[k][i][4] = weight; }
		if (win[k][i + 4][4] == 0) { win[k][i][3] = weight; win[k][i][4] = weight; win[k][i][5] = weight; }
		if (win[k][i + 5][5] == 0) { win[k][i][4] = weight; win[k][i][5] = weight; }
	}
}

void strategy::map_four()
{
	int k = 1;
	int weight = pow(10, target_num - k - 1);        // 가까운 target을 위한 가중치

	for (int i = target[k] - 5; i <= target[k] - 1; i++)
		for (int j = 1; j <= 5; j++)
			win[k][i][j] = weight;      // target 포함 아래 5개의 점수를 weight로 초기화

	win[k][target[k] - 5][1] = 0;
	win[k][target[k] - 5][2] = 0;
	win[k][target[k] - 5][3] = 0;		// target 을 획득하지 못할 수는 빼준다.

	for (int i = target[k] - 6; i > 0; i--)   // 점수를 딸 수 있는 자리에 weight를 넣어준다.
	{
		if (win[k][i + 1][1] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; }
		if (win[k][i + 2][2] == 0) { win[k][i][1] = weight; win[k][i][2] = weight; win[k][i][3] = weight; }
		if (win[k][i + 3][3] == 0) { win[k][i][2] = weight; win[k][i][3] = weight; win[k][i][4] = weight; }
		if (win[k][i + 4][4] == 0) { win[k][i][3] = weight; win[k][i][4] = weight; win[k][i][5] = weight; }
		if (win[k][i + 5][5] == 0) { win[k][i][4] = weight; win[k][i][5] = weight; }
	}
}

void strategy::sum()
{
	for (int k = 0; k < target_num; k++)
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 5; j++)
				vic[i][j] += win[k][i][j];
}

void strategy::receive(int num)
{
	rcv_num = num;
	added = rcv_num - snd_num;
	if (rcv_num >= target[0] && snd_num < target[0]) chance = true;

}

int strategy::send()
{
	if (snd_num == 0)
	{	//시작할 경우.
		snd_num = rcv_num + start();
		return snd_num;
	}
	int min(10000000);   // 가장 점수를 딸 수 없는 수.
	int add(0);     // 더할 수

	if (added != 1)
	{
		if (vic[rcv_num + (added - 1)][added - 1] < min)
		{
			min = vic[rcv_num + (added - 1)][added - 1];
			add = added - 1;
		}
	}

	if (vic[rcv_num + added][added] < min)
	{
		min = vic[rcv_num + added][added];
		add = added;
	}

	if (added != 5)
	{
		if (vic[rcv_num + (added + 1)][added + 1] < min)
		{
			min = vic[rcv_num + (added + 1)][added + 1];
			add = added + 1;
		}
	}

	if ((chance && min != 10) || (chance && min != 0))
		use_chance(add);

	snd_num = rcv_num + add;

	return snd_num;
}

int strategy::start()
{
	int min(10000000);
	int best(0);		// 보내기 가장 좋은 수. 가장 작은 수. 점수를 딸 수 없는 수.
	for (int i = 1; i <= 5; i++)
	{
		if (vic[added + i][i] < min)
		{
			min = vic[added + i][i];
			best = i;
		}
	}
	return best;
}

void strategy::use_chance(int& add)
{
	for (int i = 1; i <= 5; i++)
	{
		if ((vic[rcv_num + i][i] == 10) || (vic[rcv_num + i][i] == 0))
		{
			chance = false;
			add = i;
		}
	}
}

strategy::~strategy()
{			 // 소멸자
	delete[] target;
	target = NULL;
}

void strategy::print()
{
	for (int i = 1; i <= 100; i++)
	{
		cout << i << "\t";
		for (int j = 1; j <= 5; j++)
			cout << vic[i][j] << "\t";
		cout << endl;
	}
}
