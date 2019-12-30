#include<iostream>
using namespace std;
#include"gameCount.h"

gameCount::gameCount()
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
void gameCount::readOutput(bool output_)
{
	output = output_;
}
void gameCount::readTarget(int num, int* ptrTarget)
{
	num_Target = num;
	for (int i = 0; i < num; i++)
	{
		target[i] = ptrTarget[i];
	}
}
void gameCount::calcul_Plus(void)
{
	yourPlus = yourNum - myNum;
}
void gameCount::calcul_point(void)
{
	if (nextTarget(myNum) < nextTarget(yourNum))
	{	//내가 보냈던 수 앞에 있는 목표값을 상대가 먹었을 경우
		point--;
	}
}
void gameCount::upPoint(int num)
{
	point++;
	if (output)cout << "             ===== [ gameCount ]의 " << nextTarget(yourNum, num) << "에 대한 승점 획득! ===== <----- 알고리즘" << endl;
	
}
int gameCount::nextTarget(int gameNum, int next)
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
int gameCount::finalTarget(void)
{
	return target[num_Target - 1];
}
int gameCount::restNum(int next)
{
	return nextTarget(yourNum, next) - yourNum;
}
void gameCount::receive(int recvValue)
{
	yourNum = recvValue;
	this->calcul_Plus();
	this->calcul_point();
	if (output)cout << "   [ gameCount ]가 보낸 값은 (" << myNum << ")" << endl;
}
int gameCount::getPoint(void)
{
	return point;
}
int gameCount::search_myNum(int next) {
	int T[3] = { 0, };	// index별 가중치를 담을 배열
	int good = 1;
	for (int i = -1; i < 2; i++)
	{	//내가 i(-1,0,1)를 더해 보내고
		if (yourPlus + i < 1 || yourPlus + i > 5)
		{	//규칙에 맞지 않는 i인 경우.
			T[i + 1] = -99999999;	//가중치 다 깎아버림.
			continue;
		}

		for (int j = -1; j < 2; j++)
		{	// = = =상대가 그 수에 j(-1,0,1)를 더해 보내면 (규칙에 맞는 1~5)
			if (yourPlus + i + j < 1 || yourPlus + i + j >5)	continue;

			if (nextTarget(yourNum) - (yourNum + (yourPlus + i)) <= (yourPlus + i + j))
			{	//상대가 점수를 득점할 경우의수가 생기는 경우.
				T[i + 1] -= 10000;
				//cout << "가중치-- 현재의 i " << i << ", T[i+1]값 " << T[i + 1] << endl;
			}
			else
			{	//상대가 점수를 득점할 경우가 없고,
				for (int k = -1; k < 2; k++)
				{	// = = = 내가 그 수에 k(-1,0,1)을 더해 보내면. (규칙에 맞는 1~5)
					if (yourPlus + i + j + k < 1 || yourPlus + i + j + k > 5) continue;

					if (nextTarget(yourNum) - (yourNum + (yourPlus + i) + (yourPlus + i + j)) <= (yourPlus + i + j + k))
					{	//내가 득점할 경우가 생기면,
						T[i + 1] += 700;
						//cout << "가중치++ 현재의 i " << i << ", T[i+1]값 " << T[i + 1] << endl;
					}
					else
					{	//내가 득점을 하지 않고,
						for (int l = -1; l < 2; l++)
						{	// = = = 상대가 그 수에 l(-1,0,1)을 더해 보내면. (규칙에 맞는 1~5)
							if (yourPlus + i + j + k + l < 1 || yourPlus + i + j + k + l>5)continue;

							if (nextTarget(yourNum) - (yourNum + (yourPlus + i) + (yourPlus + i + j) + (yourPlus + i + j + k)) <= (yourPlus + i + j + k + l))
							{	//상대방이 득점할 경우가 생기면,
								T[i + 1] -= 30;
								// cout << "new가중치-- 현재의 i " << i << ", T[i+1]값 " << T[i + 1] << endl;
							}

							else
							{	//상대방이 득점하지 않고,
								for (int m = -1; m < 2; m++)
								{	// = = = 내가 그 수에 m(-1,0,1)을 더해 보내면. (규칙에 맞는 1~5)
									if (yourPlus + i + j + k + l + m < 1 || yourPlus + i + j + k + l + m > 5) continue;

									if (nextTarget(yourNum) - (yourNum + (yourPlus + i) + (yourPlus + i + j) + (yourPlus + i + j + k) + (yourPlus + i + j + k + l)) <= (yourPlus + i + j + k + l + m))
									{	//내가 득점할 경우가 생기면,
										T[i + 1] += +1;
										//cout << "new가중치++ 현재의 i " << i << ", T[i+1]값 " << T[i + 1] << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{	//최대값 갖는 index 탐색.
		if (T[good] < T[i]) good = i;
	}
	//if (output)cout << " 가중치 -1 < " << T[0] << " >  0 < " << T[1] << " > +1< " << T[2] <<" > "<<endl;
	if (yourPlus + (good - 1) < 1 && yourPlus + (good - 1) > 5) good = 1;	//규칙 검증.
	myNum = yourNum + (yourPlus + (good - 1));
	return myNum;
}
int gameCount::send(void)
{
	int rest = restNum();//근접 목표값 까지 남은 수
	if (output)
	{
		cout << endl<<"남은 목표값 ";
		for (int i = 0; nextTarget(yourNum, i) != finalTarget(); i++)
		{
			cout << nextTarget(yourNum, i)<<", ";
		}
		cout << finalTarget() << endl << endl;
	}
	if ((yourNum != 0) && (yourNum >= finalTarget()))
	{	//게임이 끝났다면 -1 반환
		if(output)cout << "gameCount : 게임 끝" << endl;
		point--;
		if (output)cout << "gameCount 기준의 승점 : " << point << endl;
		return -1;
	}

	if ((myNum == 0) && (yourNum == 0))
	{	//선수여서 첫 숫자를 던져야한다면,
								//////* 중요한 부분 보충 요망 *//////
		myNum = 3;
		return myNum;
	}

	if (chance)
	{	//찬스가 존재한다면
		if (point < 0)
		{	//승점이 뒤지고 있다면
			if ((rest > (yourPlus + 1)) && (rest <= 5))
			{	//찬스를 써서 점수를 얻을 수 있다면
				/*chance = 0;					//찬스를 소모
				myNum = yourNum + 5;		//5를 더하여 보낸다.
				upPoint();					//승점 증가
				//cout << "----------------------count의 찬스 사용------------------------" << endl;
				return myNum;				//전송값 반환.*/
				chance = 0;
				yourPlus = 4;
				if (nextTarget(yourNum) > search_myNum(1)) myNum = yourNum + 5;
				else myNum = search_myNum(1);
				upPoint();					//승점 증가
				if (output)cout << "--------------------------[ gameCount ]의 찬스 사용------------------------" << endl;
				return myNum;
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
					upPoint(1);					//승점 증가
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
						upPoint(1);					//승점 증가
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

		else
		{	//내가 근접 목표값을 득점할 수 없는 상황일 때
			//rest <=5 이고, rest > yourPlus+1 내가 보낼 수 있는 수보다 큼
			//rest만큼을 보낼 수 없다는 뜻이니 yourPlus 1~3
			//만약 yourPlus == 3이면, rest 5 이경우이다.
			//이 경우는 무조건 상대에게 먹힌다.
			//만약 yourPlus == 2이면, rest 4, 5 경우이다.
			//rest == 4 일 때, 내가 1을 넘기면 상대의 rest가 3이 되고 내가 무조건 이긴다.(O)
			//rest == 4 일 때, 내가 2을 넘기면 상대의 rest가 2가 되고 무조건 상대에게 먹힌다.(X)
			//rest == 4 일 때, 내가 3을 넘기면 상대의 rest가 1이 되고 무조건 상대에게 먹힌다.(X)
			//rest == 5 일 때, 내가 1을 넘기면 상대의 rest가 4가 되고, 다음경우가 된다 yourPlus =1,2 & rest = 3,2 이중 후자는 이긴다.(O)
			//rest == 5 일 때, 내가 2를 넘기면 상대의 rest가 3이 되고 무조건 상대에게 먹힌다.(X)
			//rest == 5 일 때, 내가 3을 넘기면 상대의 rest가 2가 되고 무조건 상대에게 먹힌다.(X)
			//만약 yourPlus == 1이면, rest 3, 4, 5 이 경우이다.
			//rest == 3 일 때, 내가 1을 넘기면 상대의 rest가 2가 되고, 무조건 상대에게 먹힌다.(X)
			//rest == 3 일 때, 내가 2를 넘기면 상대의 rest가 1이 되고, 무조건 상대에게 먹힌다.(X)
			//rest == 4 일 때, 내가 1을 넘기면 상대의 rest가 3이 되고, 내가 무조건 이긴다.(O)
			//rest == 4 일 때, 내가 2를 넘기면 상대의 rest가 2가 되고, 무조건 상대에게 먹힌다.(X)
			//rest == 5 일 때, 내가 1을 넘기면 상대의 rest가 4가 되고, 다음경우가 된다 yourPlus =1,2 & rest = 3,2 이중 후자는 이긴다.(O)
			//rest == 5 일 때, 내가 2를 넘기면 상대의 rest가 3이 되고, 무조건 상대에게 먹힌다.(X)

			//cout << " 수 작 업 알 고 리 즘 " << endl;
			//내가 그 수를 득점할 수 없는 상황일 때.rest>yourplus+1
			if (yourPlus == 3)
			{
				return search_myNum(1);
			}
			else if (yourPlus == 2)
			{
				if (rest == 4)
				{
					myNum = yourNum + 1;
					return myNum;
				}
				else if (rest == 5)
				{
					myNum = yourNum + 1;
					return myNum;
				}
				else
				{
					cout << "send()에러." << endl;
					exit(1);
				}
			}
			else if (yourPlus == 1)
			{
				if (rest == 3)
				{	//무조건 지니까 다음 탐색.

					return search_myNum(1);
				}
				else if (rest == 4)
				{	//필승
					myNum = yourNum + 1;
					return myNum;
				}
				else if (rest == 5)
				{	//경우의수 더 남음
					myNum = yourNum + 1;
					return myNum;
				}
				else
				{
					cout << "send()에러." << endl;
					exit(1);
				}
			}
			else
			{
				cout << "send()에러." << endl;
				exit(1);
			}
		}

	}
	// */

	else
	{	//근접한 목표값 까지 남은 수가 6이상일 때.
		return search_myNum();
	}
}