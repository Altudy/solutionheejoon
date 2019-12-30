#include<iostream>
using namespace std;
#include<fstream>
#include"gameTarget.h"

gameTarget::gameTarget(int a, int b, int c, int d, int e, int f, int g)
{	// 기본 생성자. num = 0, index = 0, value[7] ={0, }, check = 0.
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
{	// 선수일 때 상대에게 목표값 정보를 배열로 받는 함수.
	// 배열의 주소값을 넘겨받아 모조리 복사한다.
	// 들어온 값( num, 목표값1, 목표값2, .. )
	int j = 0;
	num = 10;
	for (int i = 0; j < num; i++)
	{
		if (tcpArray[i] > 101 || tcpArray[i] < -1)
		{
			cout << "target.receive() : 잘못된 통신값입니다(-1 ~ 101 범위 아님)";
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
	cout << "target() 저장 완료." << endl;
}
void gameTarget::select(void)
{	// 선수일 때 상대에게 받은 목표값중에 임의로 선택하는 함수.
	// 상대가 보낸 것 중 앞뒤로 2개만 선택한다.
	for (int i = 0; i < num; i++) 
	{ // 목표값 순차 정렬
		for (int j = i + 1; j < num; j++) 
		{
			if (value[i] > value[j]) 
			{ // 앞쪽 원소가 더 크면 서로 교환
				int swap = value[i];
				value[i] = value[j];
				value[j] = swap;
			}
		}
	}
	if (num > 2)
	{
		value[0] = value[0];			//첫 번째 값과
		value[1] = value[num - 1];		//마지막 값만 살리고
		for (int i = 2; i < num; i++)
		{
			value[i] = 0;				//나머지는 버림
		}
		num = 2;						//값은 2개
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
	ofstream myfile;			//파일출력 객체
	string file_name("record.txt");
	char* file_data;			//수신하게될 파일data의 pointer
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
	ifstream myfile;			//파일입력 객체
	string file_name("record.txt");	//전송할 파일의 이름(소스파일 경로)
	char* file_data;

	myfile.open(file_name);
	if (myfile.fail())
	{
		cout << "파일 읽기 실패" << endl;
	}

	file_data = new char[1];	//file size만큼 메모리공간 할당
	myfile.read(file_data, 1);	//할당한 메모리에 data reading.
	if (*file_data == '1')
	{
		cout << "직전 게임은 이겼습니다." << endl;
		max = 1;
	}
	else
	{
		cout << "직전 게임은 졌습니다." << endl;
		max = 7;
	}
	delete[] file_data;
	myfile.close();
}
int gameTarget::getNum(void)
{	// 목표값의 개수를 반환하는 함수.
	return num;
}
int* gameTarget::getPtrTarget(void)
{	// 목표값이 담긴 배열의 포인터를 반환하는 함수.
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