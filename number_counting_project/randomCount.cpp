#include <iostream>
using namespace std;
#include "randomCount.h"
#include <stdlib.h>
#include <time.h>

randomCount::randomCount()
{
	output = 0;
	chance = 1;
	pivot = 0;
	myNum = 0;
	yourNum = 0;
	yourPlus = 0;
	point = 0;
	num_Target = 0;
	//srand((unsigned)time(NULL)+50);

	for (int i = 0; i < 7; i++)
	{
		target[i] = 0;
	}
}
void randomCount::readOutput(bool output_)
{
	output = output_;
}
void randomCount::readTarget(int num, int* ptrTarget)
{
	num_Target = num;
	for (int i = 0; i < num; i++)
	{
		target[i] = ptrTarget[i];
	}
}
void randomCount::calcul_Plus(void)
{
	yourPlus = yourNum - myNum;
}
void randomCount::calcul_point(void)
{
	if (nextTarget(myNum) < nextTarget(yourNum))
	{	//내가 보냈던 수 앞에 있는 목표값을 상대가 먹었을 경우
		point--;
	}
}
void randomCount::upPoint(void)
{
	point++;
	if(output)cout << "             ===== [ RANDOM ]의 " << nextTarget(yourNum) << "에 대한 승점 획득! ===== <----- 대조군" << endl;
}
int randomCount::nextTarget(int gameNum, int next)
{
	int nextindex = 0;
	for (int i = 0; i < num_Target; i++)
	{
		if (gameNum >= target[i])
		{
			nextindex = i + 1;
		}
	}
	if ((nextindex + next) >= num_Target) 	return target[num_Target - 1]; //마지막 목표값.
	return target[nextindex + next];
}
int randomCount::finalTarget(void)
{
	return target[num_Target - 1];
}
int randomCount::restNum(int next)
{
	return nextTarget(yourNum, next) - yourNum;
}
void randomCount::receive(int recvValue)
{
	yourNum = recvValue;
	this->calcul_Plus();
	this->calcul_point();
	if (output)cout << "   [ random ]이 보낸 값은 (" << myNum << ")" << endl;
}
int randomCount::getPoint(void)
{
	return point;
}
int randomCount::send(void)
{
	int rest = restNum();//근접 목표값 까지 남은 수

	if ((myNum == 0) && (yourNum == 0))
	{	//선수여서 첫 숫자를 던져야한다면,
								//////* 중요한 부분 보충 요망 *//////
		myNum = (rand() % 5) + 1;
		return myNum;
	}

	if ((yourNum != 0) && (yourNum >= finalTarget()))
	{	//게임이 끝났다면 -1 반환
		if (output)cout << "RANDOM : 게임 끝" << endl;
		point--;
		if (output)cout << "RANDOM기준의 승점 : " << point << endl;
		return -1;
	}

	if (chance)
	{	//찬스가 존재한다면
		if (point < 0)
		{	//승점이 뒤지고 있다면
			if ((rest > (yourPlus + 1)) && (rest <= 5))
			{	//찬스를 써서 점수를 얻을 수 있다면
				chance = 0;					//찬스를 소모
				myNum = yourNum + 5;		//5를 더하여 보낸다.
				if (output)cout << "--------------------------[ RANDOM ]의 찬스 사용---------------------------" << endl;
				upPoint();					//승점 증가
				return myNum;				//전송값 반환.
			}
		}
	}

	
	if ((rest >= 1) && (rest <= 5))
	{	//근접한 목표값 까지 남은 수가 1~5일 때
		if (rest <= yourPlus + 1)
		{	//내가 그 수를 득점할 수 있는 상황일 때. 
			if (rest <= yourPlus - 1)
			{	//보낼 수 있는 범위의 어떤 수를 보내든 득점일 때.
				if ((nextTarget(yourNum, 1) - yourNum) <= (yourPlus + 1))
				{	//다다음의 타겟까지 먹을 수 있을 때.
					if (yourPlus != 5)myNum = yourNum + (yourPlus + 1);	//최대값 전송
					else myNum = yourNum + (yourPlus);
					if (nextTarget(yourNum, 1) != finalTarget() && nextTarget(yourNum, 1) - myNum <= 0)
					{
						upPoint();					//승점 증가						
						if (nextTarget(yourNum, 2) - myNum <= 0)
						{
							upPoint();					//승점 증가
							if (nextTarget(yourNum, 3) - myNum <= 0)
							{
								upPoint();					//승점 증가
							}
						}
					}
					upPoint();					//승점 증가
					return myNum;
				}
				myNum = yourNum + yourPlus;
				if ((nextTarget(yourNum, 1) - myNum >= 0) && (nextTarget(yourNum, 1) - myNum <= 6))
				{	//내가 보낸 후 상대방이 득점기회가 생길 수도 있는 경우가 있으면,
					if (yourPlus != 1)
					{
						myNum = yourNum + (yourPlus - 1);
						upPoint();					//승점 증가
						return myNum;
					}
					return myNum;
				}
				else
				{	//내가 뭘보내도 다음 상대턴엔 득점기회가 없으면.
					if (nextTarget(yourNum, 1) - (yourNum + (yourPlus * 2)) <= 5)
					{	//다음 내차례때 득점기회가 있을 수도 있으면,
						if (yourPlus != 5)myNum = yourNum + (yourPlus + 1);
						else myNum = yourNum + (yourPlus);
						upPoint();					//승점 증가
						return myNum;
					}
					else
					{
						if (yourPlus != 1)myNum = yourNum + (yourPlus - 1);
						else myNum = yourNum + (yourPlus);
						upPoint();					//승점 증가
						return myNum;
					}
				}
			}
			else
			{	//보낼 수 있는 범위의 특정값 이상 더해서 보내야 득점일 때.
				if (finalTarget() != nextTarget(yourNum, 1) && (nextTarget(yourNum, 1) - yourNum) <= yourPlus + 1)
				{	//다다음의 타겟까지 먹을 수 있을 때.
					if (yourPlus != 5)myNum = yourNum + (yourPlus + 1);	//최대값 전송
					else myNum = yourNum + (yourPlus);
					if (nextTarget(yourNum, 1) - myNum <= 0)
					{
						upPoint();					//승점 증가
						if (nextTarget(yourNum, 2) - myNum <= 0)
						{
							upPoint();					//승점 증가
							if (nextTarget(yourNum, 3) - myNum <= 0)
							{
								upPoint();					//승점 증가
							}
						}
					}
					upPoint();					//승점 증가
					return myNum;
				}
				else
				{	//타겟을 하나만 먹을 수 있을 때, 그 수까지만 전송.
					myNum = yourNum + rest;
					upPoint();					//승점 증가
					return myNum;
				}
			}
		}
	}
		// 바로 앞의 목표값은 먹도록 알고리즘. */


	if (yourPlus == 1)
	{
		random = rand() % 2;	//0~1중의 랜덤값.
		myNum = yourNum + (yourPlus + random);
	}
	else if (yourPlus == 5)
	{
		random = (rand() % 2) - 1;	//-1,0중의 랜덤값.
		if (random == 1) random = 0;
		myNum = yourNum + (yourPlus + random);
	}
	else
	{
		random = rand() % 3;	//0~2중의 랜덤값.
		if (random == 2) random = -1;	//-1,0,1의 랜덤값으로 만들어줌.
		myNum = yourNum + (yourPlus + random);
	}
	if (nextTarget(yourNum, 0) - myNum <= 0)
	{
		upPoint();					//승점 증가
		if (nextTarget(yourNum, 1) != finalTarget() && nextTarget(yourNum, 1) - myNum <= 0)
		{
			upPoint();					//승점 증가
		}
	}
	return myNum;
}