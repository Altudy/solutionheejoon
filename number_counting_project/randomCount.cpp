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
	{	//���� ���´� �� �տ� �ִ� ��ǥ���� ��밡 �Ծ��� ���
		point--;
	}
}
void randomCount::upPoint(void)
{
	point++;
	if(output)cout << "             ===== [ RANDOM ]�� " << nextTarget(yourNum) << "�� ���� ���� ȹ��! ===== <----- ������" << endl;
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
	if ((nextindex + next) >= num_Target) 	return target[num_Target - 1]; //������ ��ǥ��.
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
	if (output)cout << "   [ random ]�� ���� ���� (" << myNum << ")" << endl;
}
int randomCount::getPoint(void)
{
	return point;
}
int randomCount::send(void)
{
	int rest = restNum();//���� ��ǥ�� ���� ���� ��

	if ((myNum == 0) && (yourNum == 0))
	{	//�������� ù ���ڸ� �������Ѵٸ�,
								//////* �߿��� �κ� ���� ��� *//////
		myNum = (rand() % 5) + 1;
		return myNum;
	}

	if ((yourNum != 0) && (yourNum >= finalTarget()))
	{	//������ �����ٸ� -1 ��ȯ
		if (output)cout << "RANDOM : ���� ��" << endl;
		point--;
		if (output)cout << "RANDOM������ ���� : " << point << endl;
		return -1;
	}

	if (chance)
	{	//������ �����Ѵٸ�
		if (point < 0)
		{	//������ ������ �ִٸ�
			if ((rest > (yourPlus + 1)) && (rest <= 5))
			{	//������ �Ἥ ������ ���� �� �ִٸ�
				chance = 0;					//������ �Ҹ�
				myNum = yourNum + 5;		//5�� ���Ͽ� ������.
				if (output)cout << "--------------------------[ RANDOM ]�� ���� ���---------------------------" << endl;
				upPoint();					//���� ����
				return myNum;				//���۰� ��ȯ.
			}
		}
	}

	
	if ((rest >= 1) && (rest <= 5))
	{	//������ ��ǥ�� ���� ���� ���� 1~5�� ��
		if (rest <= yourPlus + 1)
		{	//���� �� ���� ������ �� �ִ� ��Ȳ�� ��. 
			if (rest <= yourPlus - 1)
			{	//���� �� �ִ� ������ � ���� ������ ������ ��.
				if ((nextTarget(yourNum, 1) - yourNum) <= (yourPlus + 1))
				{	//�ٴ����� Ÿ�ٱ��� ���� �� ���� ��.
					if (yourPlus != 5)myNum = yourNum + (yourPlus + 1);	//�ִ밪 ����
					else myNum = yourNum + (yourPlus);
					if (nextTarget(yourNum, 1) != finalTarget() && nextTarget(yourNum, 1) - myNum <= 0)
					{
						upPoint();					//���� ����						
						if (nextTarget(yourNum, 2) - myNum <= 0)
						{
							upPoint();					//���� ����
							if (nextTarget(yourNum, 3) - myNum <= 0)
							{
								upPoint();					//���� ����
							}
						}
					}
					upPoint();					//���� ����
					return myNum;
				}
				myNum = yourNum + yourPlus;
				if ((nextTarget(yourNum, 1) - myNum >= 0) && (nextTarget(yourNum, 1) - myNum <= 6))
				{	//���� ���� �� ������ ������ȸ�� ���� ���� �ִ� ��찡 ������,
					if (yourPlus != 1)
					{
						myNum = yourNum + (yourPlus - 1);
						upPoint();					//���� ����
						return myNum;
					}
					return myNum;
				}
				else
				{	//���� �������� ���� ����Ͽ� ������ȸ�� ������.
					if (nextTarget(yourNum, 1) - (yourNum + (yourPlus * 2)) <= 5)
					{	//���� �����ʶ� ������ȸ�� ���� ���� ������,
						if (yourPlus != 5)myNum = yourNum + (yourPlus + 1);
						else myNum = yourNum + (yourPlus);
						upPoint();					//���� ����
						return myNum;
					}
					else
					{
						if (yourPlus != 1)myNum = yourNum + (yourPlus - 1);
						else myNum = yourNum + (yourPlus);
						upPoint();					//���� ����
						return myNum;
					}
				}
			}
			else
			{	//���� �� �ִ� ������ Ư���� �̻� ���ؼ� ������ ������ ��.
				if (finalTarget() != nextTarget(yourNum, 1) && (nextTarget(yourNum, 1) - yourNum) <= yourPlus + 1)
				{	//�ٴ����� Ÿ�ٱ��� ���� �� ���� ��.
					if (yourPlus != 5)myNum = yourNum + (yourPlus + 1);	//�ִ밪 ����
					else myNum = yourNum + (yourPlus);
					if (nextTarget(yourNum, 1) - myNum <= 0)
					{
						upPoint();					//���� ����
						if (nextTarget(yourNum, 2) - myNum <= 0)
						{
							upPoint();					//���� ����
							if (nextTarget(yourNum, 3) - myNum <= 0)
							{
								upPoint();					//���� ����
							}
						}
					}
					upPoint();					//���� ����
					return myNum;
				}
				else
				{	//Ÿ���� �ϳ��� ���� �� ���� ��, �� �������� ����.
					myNum = yourNum + rest;
					upPoint();					//���� ����
					return myNum;
				}
			}
		}
	}
		// �ٷ� ���� ��ǥ���� �Ե��� �˰���. */


	if (yourPlus == 1)
	{
		random = rand() % 2;	//0~1���� ������.
		myNum = yourNum + (yourPlus + random);
	}
	else if (yourPlus == 5)
	{
		random = (rand() % 2) - 1;	//-1,0���� ������.
		if (random == 1) random = 0;
		myNum = yourNum + (yourPlus + random);
	}
	else
	{
		random = rand() % 3;	//0~2���� ������.
		if (random == 2) random = -1;	//-1,0,1�� ���������� �������.
		myNum = yourNum + (yourPlus + random);
	}
	if (nextTarget(yourNum, 0) - myNum <= 0)
	{
		upPoint();					//���� ����
		if (nextTarget(yourNum, 1) != finalTarget() && nextTarget(yourNum, 1) - myNum <= 0)
		{
			upPoint();					//���� ����
		}
	}
	return myNum;
}