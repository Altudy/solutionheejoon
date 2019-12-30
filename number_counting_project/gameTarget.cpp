#include<iostream>
using namespace std;
#include<fstream>
#include"gameTarget.h"

gameTarget::gameTarget(int a, int b, int c, int d, int e, int f, int g)
{	// �⺻ ������. num = 0, index = 0, value[7] ={0, }, check = 0.
	num = 0;
	index = 0;
	check = 0;
	max = 0;
	value[0] = a;
	value[1] = b;
	value[2] = c;
	value[3] = d;
	value[4] = e;
	value[5] = f;
	value[6] = g;
	for (int i = 0; i < 7; i++)
	{
		if (value[i] != 0) num++;
	}
}
void gameTarget::receive(int* tcpArray)
{	// ������ �� ��뿡�� ��ǥ�� ������ �迭�� �޴� �Լ�.
	// �迭�� �ּҰ��� �Ѱܹ޾� ������ �����Ѵ�.
	// ���� ��( num, ��ǥ��1, ��ǥ��2, .. )
	int j = 0;
	num = 10;
	for (int i = 0; j < num; i++)
	{
		if (tcpArray[i] > 101 || tcpArray[i] < -1)
		{
			cout << "target.receive() : �߸��� ��Ű��Դϴ�(-1 ~ 101 ���� �ƴ�)";
			exit(1);
		}
		if (tcpArray[i] == 101) continue;
		if (tcpArray[i] == -1) break;
		if (tcpArray[i] <= 7 && tcpArray[i] >= 1) num = tcpArray[i];
		else
		{
			value[j] = tcpArray[i];
			j++;
		}
	}
	cout << "target() ���� �Ϸ�." << endl;
}
void gameTarget::select(void)
{	// ������ �� ��뿡�� ���� ��ǥ���߿� ���Ƿ� �����ϴ� �Լ�.
	// ��밡 ���� �� �� �յڷ� 2���� �����Ѵ�.
	for (int i = 0; i < num; i++) 
	{ // ��ǥ�� ���� ����
		for (int j = i + 1; j < num; j++) 
		{
			if (value[i] > value[j]) 
			{ // ���� ���Ұ� �� ũ�� ���� ��ȯ
				int swap = value[i];
				value[i] = value[j];
				value[j] = swap;
			}
		}
	}
	if (num > 2)
	{
		value[0] = value[0];			//ù ��° ����
		value[1] = value[num - 1];		//������ ���� �츮��
		for (int i = 2; i < num; i++)
		{
			value[i] = 0;				//�������� ����
		}
		num = 2;						//���� 2��
	}
}
int gameTarget::nextValue(int nowNum, int next)
{
	int nextindex = 0;
	for (int i = 0; i < num; i++)
	{
		if (nowNum >= value[i])
		{
			nextindex = i + 1;
		}
	}
	if ((nextindex + next) >= num) 	return value[num - 1];
	return value[nextindex + next];
}
int gameTarget::finalValue(void)
{
	return value[num - 1];
}
void gameTarget::saveResult(bool win)
{
	ofstream myfile;			//������� ��ü
	string file_name("record.txt");
	char* file_data;			//�����ϰԵ� ����data�� pointer
	file_data = new char[1];

	if (win) *file_data = '1';
	else *file_data = '0';

	ofstream outfile(file_name);
	outfile.write(file_data, 1);
	delete[] file_data;
	outfile.close();
}
void gameTarget::loadResult(void)
{
	ifstream myfile;			//�����Է� ��ü
	string file_name("record.txt");	//������ ������ �̸�(�ҽ����� ���)
	char* file_data;

	myfile.open(file_name);
	if (myfile.fail())
	{
		cout << "���� �б� ����" << endl;
	}

	file_data = new char[1];	//file size��ŭ �޸𸮰��� �Ҵ�
	myfile.read(file_data, 1);	//�Ҵ��� �޸𸮿� data reading.
	if (*file_data == '1')
	{
		cout << "���� ������ �̰���ϴ�." << endl;
		max = 1;
	}
	else
	{
		cout << "���� ������ �����ϴ�." << endl;
		max = 7;
	}
	delete[] file_data;
	myfile.close();
}
int gameTarget::getNum(void)
{	// ��ǥ���� ������ ��ȯ�ϴ� �Լ�.
	return num;
}
int* gameTarget::getPtrTarget(void)
{	// ��ǥ���� ��� �迭�� �����͸� ��ȯ�ϴ� �Լ�.
	return value;
}
int* gameTarget::tcpPtr(void)
{
	tcpArray[0] = 101;
	tcpArray[1] = num;
	for (int i = 0; 1; i++)
	{
		if (i == num)
		{
			tcpArray[i + 2] = -1;
			break;
		}
		tcpArray[i + 2] = value[i];
	}
	return tcpArray;
}