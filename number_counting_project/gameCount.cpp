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
	{	//���� ���´� �� �տ� �ִ� ��ǥ���� ��밡 �Ծ��� ���
		point--;
	}
}
void gameCount::upPoint(int num)
{
	point++;
	if (output)cout << "             ===== [ gameCount ]�� " << nextTarget(yourNum, num) << "�� ���� ���� ȹ��! ===== <----- �˰���" << endl;
	
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
	if ((nextindex + next) >= num_Target) 	return target[num_Target - 1]; //������ ��ǥ��.
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
	if (output)cout << "   [ gameCount ]�� ���� ���� (" << myNum << ")" << endl;
}
int gameCount::getPoint(void)
{
	return point;
}
int gameCount::search_myNum(int next) {
	int T[3] = { 0, };	// index�� ����ġ�� ���� �迭
	int good = 1;
	for (int i = -1; i < 2; i++)
	{	//���� i(-1,0,1)�� ���� ������
		if (yourPlus + i < 1 || yourPlus + i > 5)
		{	//��Ģ�� ���� �ʴ� i�� ���.
			T[i + 1] = -99999999;	//����ġ �� ��ƹ���.
			continue;
		}

		for (int j = -1; j < 2; j++)
		{	// = = =��밡 �� ���� j(-1,0,1)�� ���� ������ (��Ģ�� �´� 1~5)
			if (yourPlus + i + j < 1 || yourPlus + i + j >5)	continue;

			if (nextTarget(yourNum) - (yourNum + (yourPlus + i)) <= (yourPlus + i + j))
			{	//��밡 ������ ������ ����Ǽ��� ����� ���.
				T[i + 1] -= 10000;
				//cout << "����ġ-- ������ i " << i << ", T[i+1]�� " << T[i + 1] << endl;
			}
			else
			{	//��밡 ������ ������ ��찡 ����,
				for (int k = -1; k < 2; k++)
				{	// = = = ���� �� ���� k(-1,0,1)�� ���� ������. (��Ģ�� �´� 1~5)
					if (yourPlus + i + j + k < 1 || yourPlus + i + j + k > 5) continue;

					if (nextTarget(yourNum) - (yourNum + (yourPlus + i) + (yourPlus + i + j)) <= (yourPlus + i + j + k))
					{	//���� ������ ��찡 �����,
						T[i + 1] += 700;
						//cout << "����ġ++ ������ i " << i << ", T[i+1]�� " << T[i + 1] << endl;
					}
					else
					{	//���� ������ ���� �ʰ�,
						for (int l = -1; l < 2; l++)
						{	// = = = ��밡 �� ���� l(-1,0,1)�� ���� ������. (��Ģ�� �´� 1~5)
							if (yourPlus + i + j + k + l < 1 || yourPlus + i + j + k + l>5)continue;

							if (nextTarget(yourNum) - (yourNum + (yourPlus + i) + (yourPlus + i + j) + (yourPlus + i + j + k)) <= (yourPlus + i + j + k + l))
							{	//������ ������ ��찡 �����,
								T[i + 1] -= 30;
								// cout << "new����ġ-- ������ i " << i << ", T[i+1]�� " << T[i + 1] << endl;
							}

							else
							{	//������ �������� �ʰ�,
								for (int m = -1; m < 2; m++)
								{	// = = = ���� �� ���� m(-1,0,1)�� ���� ������. (��Ģ�� �´� 1~5)
									if (yourPlus + i + j + k + l + m < 1 || yourPlus + i + j + k + l + m > 5) continue;

									if (nextTarget(yourNum) - (yourNum + (yourPlus + i) + (yourPlus + i + j) + (yourPlus + i + j + k) + (yourPlus + i + j + k + l)) <= (yourPlus + i + j + k + l + m))
									{	//���� ������ ��찡 �����,
										T[i + 1] += +1;
										//cout << "new����ġ++ ������ i " << i << ", T[i+1]�� " << T[i + 1] << endl;
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
	{	//�ִ밪 ���� index Ž��.
		if (T[good] < T[i]) good = i;
	}
	//if (output)cout << " ����ġ -1 < " << T[0] << " >  0 < " << T[1] << " > +1< " << T[2] <<" > "<<endl;
	if (yourPlus + (good - 1) < 1 && yourPlus + (good - 1) > 5) good = 1;	//��Ģ ����.
	myNum = yourNum + (yourPlus + (good - 1));
	return myNum;
}
int gameCount::send(void)
{
	int rest = restNum();//���� ��ǥ�� ���� ���� ��
	if (output)
	{
		cout << endl<<"���� ��ǥ�� ";
		for (int i = 0; nextTarget(yourNum, i) != finalTarget(); i++)
		{
			cout << nextTarget(yourNum, i)<<", ";
		}
		cout << finalTarget() << endl << endl;
	}
	if ((yourNum != 0) && (yourNum >= finalTarget()))
	{	//������ �����ٸ� -1 ��ȯ
		if(output)cout << "gameCount : ���� ��" << endl;
		point--;
		if (output)cout << "gameCount ������ ���� : " << point << endl;
		return -1;
	}

	if ((myNum == 0) && (yourNum == 0))
	{	//�������� ù ���ڸ� �������Ѵٸ�,
								//////* �߿��� �κ� ���� ��� *//////
		myNum = 3;
		return myNum;
	}

	if (chance)
	{	//������ �����Ѵٸ�
		if (point < 0)
		{	//������ ������ �ִٸ�
			if ((rest > (yourPlus + 1)) && (rest <= 5))
			{	//������ �Ἥ ������ ���� �� �ִٸ�
				/*chance = 0;					//������ �Ҹ�
				myNum = yourNum + 5;		//5�� ���Ͽ� ������.
				upPoint();					//���� ����
				//cout << "----------------------count�� ���� ���------------------------" << endl;
				return myNum;				//���۰� ��ȯ.*/
				chance = 0;
				yourPlus = 4;
				if (nextTarget(yourNum) > search_myNum(1)) myNum = yourNum + 5;
				else myNum = search_myNum(1);
				upPoint();					//���� ����
				if (output)cout << "--------------------------[ gameCount ]�� ���� ���------------------------" << endl;
				return myNum;
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
					upPoint(1);					//���� ����
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
						upPoint(1);					//���� ����
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

		else
		{	//���� ���� ��ǥ���� ������ �� ���� ��Ȳ�� ��
			//rest <=5 �̰�, rest > yourPlus+1 ���� ���� �� �ִ� ������ ŭ
			//rest��ŭ�� ���� �� ���ٴ� ���̴� yourPlus 1~3
			//���� yourPlus == 3�̸�, rest 5 �̰���̴�.
			//�� ���� ������ ��뿡�� ������.
			//���� yourPlus == 2�̸�, rest 4, 5 ����̴�.
			//rest == 4 �� ��, ���� 1�� �ѱ�� ����� rest�� 3�� �ǰ� ���� ������ �̱��.(O)
			//rest == 4 �� ��, ���� 2�� �ѱ�� ����� rest�� 2�� �ǰ� ������ ��뿡�� ������.(X)
			//rest == 4 �� ��, ���� 3�� �ѱ�� ����� rest�� 1�� �ǰ� ������ ��뿡�� ������.(X)
			//rest == 5 �� ��, ���� 1�� �ѱ�� ����� rest�� 4�� �ǰ�, ������찡 �ȴ� yourPlus =1,2 & rest = 3,2 ���� ���ڴ� �̱��.(O)
			//rest == 5 �� ��, ���� 2�� �ѱ�� ����� rest�� 3�� �ǰ� ������ ��뿡�� ������.(X)
			//rest == 5 �� ��, ���� 3�� �ѱ�� ����� rest�� 2�� �ǰ� ������ ��뿡�� ������.(X)
			//���� yourPlus == 1�̸�, rest 3, 4, 5 �� ����̴�.
			//rest == 3 �� ��, ���� 1�� �ѱ�� ����� rest�� 2�� �ǰ�, ������ ��뿡�� ������.(X)
			//rest == 3 �� ��, ���� 2�� �ѱ�� ����� rest�� 1�� �ǰ�, ������ ��뿡�� ������.(X)
			//rest == 4 �� ��, ���� 1�� �ѱ�� ����� rest�� 3�� �ǰ�, ���� ������ �̱��.(O)
			//rest == 4 �� ��, ���� 2�� �ѱ�� ����� rest�� 2�� �ǰ�, ������ ��뿡�� ������.(X)
			//rest == 5 �� ��, ���� 1�� �ѱ�� ����� rest�� 4�� �ǰ�, ������찡 �ȴ� yourPlus =1,2 & rest = 3,2 ���� ���ڴ� �̱��.(O)
			//rest == 5 �� ��, ���� 2�� �ѱ�� ����� rest�� 3�� �ǰ�, ������ ��뿡�� ������.(X)

			//cout << " �� �� �� �� �� �� �� " << endl;
			//���� �� ���� ������ �� ���� ��Ȳ�� ��.rest>yourplus+1
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
					cout << "send()����." << endl;
					exit(1);
				}
			}
			else if (yourPlus == 1)
			{
				if (rest == 3)
				{	//������ ���ϱ� ���� Ž��.

					return search_myNum(1);
				}
				else if (rest == 4)
				{	//�ʽ�
					myNum = yourNum + 1;
					return myNum;
				}
				else if (rest == 5)
				{	//����Ǽ� �� ����
					myNum = yourNum + 1;
					return myNum;
				}
				else
				{
					cout << "send()����." << endl;
					exit(1);
				}
			}
			else
			{
				cout << "send()����." << endl;
				exit(1);
			}
		}

	}
	// */

	else
	{	//������ ��ǥ�� ���� ���� ���� 6�̻��� ��.
		return search_myNum();
	}
}