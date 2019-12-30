#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <WinSock2.h>
#include "gameCount.h"
#include "gameTarget.h"
#include "Judge.h"
#include "randomCount.h"
#include "strategy.h"
using namespace std;
#define PORT 1111
#define SERVER_IP "192.168.219.196"		//��밡 �����ϰ�� ip�ۼ�.
void outputTcp(char* array_ch, bool my);
//tcp��ŵ� ���� ������ִ� �Լ�.

int main(void)
{
	WSADATA wsaData;
	SOCKET ServSoc;
	SOCKET TcpSoc;
	SOCKADDR_IN ServSocAddr = { 0, };
	SOCKADDR_IN TcpSocAddr = { 0, };
	gameTarget target(99);				//��ǥ�� class ����� ���ÿ� �ļ��� �� ���� ��ǥ�� ����(constructor)
	srand((unsigned)time(NULL));		//������ ������ ���� ��ó��
	bool tcpOption;						//�������1,	Ŭ���̾�Ʈ0
	bool gameMode;						//�ļ�1,		����0
	bool output = 0;					//��� ����
	bool output_judge = 1;				//judgeŬ���� ��� ���
	int tcpArray[10] = { 0, };			//tcp ���� ��� int �迭
	char tcpArray_ch[10] = { 0, };		//tcp ���� ��� char �迭
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << ("���� ���� ����!");
		exit(1);
	}//���� �ʱ�ȭ ���� �� 0 ��ȯ, �� ���� ��쿣 ����		
	cout << "<< ������α׷��� Number Counting Game ������Ʈ 2�� >>" << endl << endl;
	cout << "TCP/IP ��� ��带 �����Ͻʽÿ�(0.client, 1.server) : ";
	cin >> tcpOption;					//TCP��� ����.
	if (tcpOption)
	{	//���� ��ó��
		cout << endl << "server��� �Դϴ�." << endl;
		ServSoc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//���� ���� -> 32bit �ּ� ü��, ���� ���⼺, TCP��� ����� �ǹ�
		ServSocAddr.sin_family = AF_INET;					//IPv4 protocol
		ServSocAddr.sin_port = htons(PORT);					//Port ��ȣ ����
		ServSocAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//���� ���α׷��� �����Ǵ� ��ǻ���� IP�ּҷ� �������ش�.
		bind(ServSoc, (SOCKADDR*)&ServSocAddr, sizeof(ServSocAddr));//24~30���� ������ ������ �ּ������� ���Ͽ� �����ش�.
		listen(ServSoc, SOMAXCONN);							//SOMAXCONN�� �ִ� ���� ��
		int TcpSoc_size = sizeof(TcpSocAddr);
		cout << "server��� ��ó�� �Ϸ�." << endl << endl;
		cout << "Ŭ���̾�Ʈ ���� �����..." << endl;
		TcpSoc = accept(ServSoc, (SOCKADDR*)&TcpSocAddr, &TcpSoc_size);//cnt ���� ���� ���. ���ӿ�û�� ���.
		cout << "Ŭ���̾�Ʈ ���� Ȯ��." << endl << endl;
	}
	else
	{	//Ŭ���̾�Ʈ ��ó��
		cout << endl << "client��� �Դϴ�." << endl;
		TcpSoc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		TcpSocAddr.sin_family = AF_INET;
		TcpSocAddr.sin_port = htons(PORT);
		TcpSocAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
		cout << "client��� ��ó�� �Ϸ�." << endl << endl;
		cout << "���� ���� �����..." << endl;
		connect(TcpSoc, (SOCKADDR*)&TcpSocAddr, sizeof(TcpSocAddr));	//accept�� ¦��.
		cout << "���� ���� Ȯ��." << endl << endl;
	}
	/* �� �κ� TCP ��� ��ó�� */

	cout << "������ �����Ͻʽÿ�(0.����, 1.�ļ�) : ";
	cin >> gameMode;
	gameCount count01;					//�˰��� class
	randomCount random01;				//���� class (���� ��밡��, �Ÿ� 5�̳��� ��ǥ���� ����)
	strategy strategy01;				//������ �˰���
	Judge judge;
	judge.readOutput(output_judge);		//��¸�� ����.
	int T = 1;							//��Ű��� �Ű�����.
	char* X = NULL;						//����� �� �ӽ�������.
	X = new char;						//
	int len = 0;						//���Ű��� ���̸� ���� ����.
	int j = 0;							//target �ѱ涧 �� �ʿ��� index.

	switch (gameMode)				//���ù��� ��忡 ����
	{
	case 0:		//count�� ������ ���̽�
		cout << "������ ������ �����մϴ�." << endl << endl;
		len = recv(TcpSoc, tcpArray_ch, 10, 0);		//TCP��ǥ�� ����
		if (len == 1)
		{
			*X = 0;
			for (int i = 1; *X != -1; i++)
			{
				recv(TcpSoc, X, 10, 0);		//TCP�� ����
				tcpArray_ch[i] = *X;
			}
		}
		//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
		outputTcp(tcpArray_ch, 0);

		for (int i = 0; i < 10; i++)
		{	// int <= char �迭��ȯ
			tcpArray[i] = (int)tcpArray_ch[i];
		}
		target.receive(tcpArray);				//target�� ����Ǹ�ǥ�� �Է�
		target.select();						//���� ����	��ǥ���� ����
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)tcpArray[i] = 101;
			else if (i == 1)tcpArray[i] = target.getNum();
			else if (i == target.getNum() + 2)
			{
				tcpArray[i] = -1;
				break;
			}
			else tcpArray[i] = target.getPtrTarget()[j++];
		}
		for (int i = 0; i < 10; i++)
		{	// char <= int �迭��ȯ
			tcpArray_ch[i] = (char)tcpArray[i];
		}

		send(TcpSoc, tcpArray_ch, target.getNum() + 3, 0);	//TCP��ǥ�� ����
		outputTcp(tcpArray_ch, 1);
		strategy01.readTarget(target.getNum(), target.getPtrTarget());	//�˰��� �� ��ǥ�� �Է�
		judge.SetGoalValue_First(target.getNum(), target.getPtrTarget());//judge �� ��ǥ�� �Է� ��������
		strategy01.map_first();											//�������� �˰��� �Լ�.

		for (int i = 0; i < 10; i++)
		{	//tcp�迭 �ʱ�ȭ
			if (i == 0)
			{
				tcpArray[i] = 101;
				tcpArray_ch[i] = 101;
			}
			else if (i == 1)
			{
				tcpArray[i] = 0;
				tcpArray_ch[i] = 0;
			}
			else if (i == 2)
			{
				tcpArray[i] = -1;
				tcpArray_ch[i] = -1;
			}
			else
			{
				tcpArray[i] = NULL;
				tcpArray_ch[i] = NULL;
			}
		}
		while (1)
		{	//�ְ�޴� �� ����Ŭ. array�� (101, 0, -1)����
			T = strategy01.send();					//�˰��� ����
			tcpArray[1] = T;					//���� ���� tcp_int�迭�� ��´�
			tcpArray_ch[1] = (char)tcpArray[1];	//int -> char �迭��ȯ
			send(TcpSoc, tcpArray_ch, 3, 0);	//TCP����
			outputTcp(tcpArray_ch, 1);
			judge.CheckMyTurn(T);				//��ȿ�� ����
			if (judge.GetFinish())
			{	//���� ���� ���´µ� ������ ������

				if (judge.GetMyVic())
				{	//������� �й������ �޾ƾ���.
					cout << "���� �й� ������ �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�й� ������ �޾ҽ��ϴ�. �¸� ���� ������ ��������." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "��밡 �й� ����(104, -1)�� ������ �ʾҽ��ϴ�." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							cout << "�¸� ����(103, -1)�� ������ ���� ����." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "��밡 �й� ����(104, -1)�� ������ �ʾҽ��ϴ�." << endl;
						tcpArray_ch[0] = 103;
						tcpArray_ch[1] = -1;
						cout << "�¸� ����(103, -1)�� ������ ���� ����." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//������� �¸������� �޾ƾ���.
					cout << "���� �¸������� �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�¸� ������ �޾ҽ��ϴ�. �й���� ������ ��������." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "��밡 �¸� ����(103, -1)�� ������ �ʾҽ��ϴ�." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							cout << "�й� ����(104, -1)�� ������ ���� ����." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "��밡 �¸� ����(103, -1)�� ������ �ʾҽ��ϴ�." << endl;
						tcpArray_ch[0] = 104;
						tcpArray_ch[1] = -1;
						cout << "�й� ����(104, -1)�� ������ ���� ����." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else
				{	//���º�
					cout << "�����ϴ�.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
					outputTcp(tcpArray_ch, 1);
				}
				break;
			}

			len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
			if (len == 1)
			{
				*X = 0;
				for (int i = 1; *X != -1; i++)
				{
					recv(TcpSoc, X, 10, 0);		//TCP�� ����
					tcpArray_ch[i] = *X;
				}
			}
			//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
			outputTcp(tcpArray_ch, 0);
			for (int i = 0; i < 10; i++)
			{	// int <= char �迭��ȯ
				tcpArray[i] = (int)tcpArray_ch[i];
			}
			judge.CheckYourTurn(tcpArray);		//��ȿ�� ����
			if (judge.GetFinish())
			{	//���� ���������� �޾Ҵµ� ������ ������
				for (int i = 0; i < 10; i++)
				{	// int <= char �迭��ȯ
					tcpArray[i] = (int)tcpArray_ch[i];
				}

				if (judge.GetMyVic())
				{	//�¸������� ������.
					tcpArray_ch[0] = 103;
					tcpArray_ch[1] = -1;
					cout << "�¸� ������ �����մϴ�(103, -1)" << endl;
					send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
					//�й������ �޾ƾ� ��.
					outputTcp(tcpArray_ch, 1);
					cout << "���� �й������ �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�й� ������ �޾ҽ��ϴ�. ��������." << endl;
							break;
						}
						else
						{
							cout << "���� ���� �й�����Դϴ�." << endl;
							break;
						}
					}
					else
					{
						cout << "��밡 �й������ ������ �ʾҽ��ϴ�." << endl;
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//�й������ ������.
					tcpArray_ch[0] = 104;
					tcpArray_ch[1] = -1;
					send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
					//�¸������� �޾ƾ���.
					outputTcp(tcpArray_ch, 1);
					cout << "���� �¸������� �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�¸� ������ �޾ҽ��ϴ�. ��������." << endl;
							break;
						}
						else
						{
							cout << "���� ���� �¸������Դϴ�." << endl;
							break;
						}
					}
					else
					{
						cout << "��밡 �¸������� ������ �ʾҽ��ϴ�." << endl;
						break;
					}
				}
				else
				{	//���º�
					cout << "�����ϴ�.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
					outputTcp(tcpArray_ch, 1);
					break;
				}
			}
			strategy01.receive(tcpArray[1]);		//����� �� �Է�
		}

		break;	//case 0 ����

	case 1:		//count�� �ļ��� ���̽�
		cout << "�ļ��� ������ �����մϴ�." << endl << endl;
		//target -> array
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)tcpArray[i] = 101;
			else if (i == 1)tcpArray[i] = target.getNum();
			else if (i == target.getNum() + 2)
			{
				tcpArray[i] = -1;
				break;
			}
			else
			{
				tcpArray[i] = target.getPtrTarget()[j];
				j++;
			}
		}
		for (int i = 0; i < 10; i++)
		{	// char <= int �迭��ȯ
			tcpArray_ch[i] = (char)tcpArray[i];
		}

		send(TcpSoc, tcpArray_ch, target.getNum() + 3, 0);	//TCP��ǥ�� ����
		outputTcp(tcpArray_ch, 1);
		len = recv(TcpSoc, tcpArray_ch, 10, 0);				//TCP��ǥ�� ����
		if (len == 1)
		{
			*X = 0;
			for (int i = 1; *X != -1; i++)
			{
				recv(TcpSoc, X, 10, 0);		//TCP�� ����
				tcpArray_ch[i] = *X;
			}
		}
		//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
		outputTcp(tcpArray_ch, 0);

		for (int i = 0; i < 10; i++)
		{	// int <= char �迭��ȯ
			tcpArray[i] = (int)tcpArray_ch[i];
		}
		target.receive(tcpArray);				//target�� ����Ǹ�ǥ�� �Է�
		judge.SetGoalValue_Second(tcpArray);	//judge�� ����� ��ǥ���� ����(�Է�)
		strategy01.readTarget(target.getNum(), target.getPtrTarget());	//�˰��� ��ǥ�� �Է�
		strategy01.map_second();											//�������� �˰��� �Լ�.

		for (int i = 0; i < 10; i++)
		{	//tcp�迭 �ʱ�ȭ
			if (i == 0)
			{
				tcpArray[i] = 101;
				tcpArray_ch[i] = 101;
			}
			else if (i == 1)
			{
				tcpArray[i] = 0;
				tcpArray_ch[i] = 0;
			}
			else if (i == 2)
			{
				tcpArray[i] = -1;
				tcpArray_ch[i] = -1;
			}
			else
			{
				tcpArray[i] = NULL;
				tcpArray_ch[i] = NULL;
			}
		}
		while (1)
		{
			len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
			if (len == 1)
			{
				*X = 0;
				for (int i = 1; *X != -1; i++)
				{
					recv(TcpSoc, X, 10, 0);		//TCP�� ����
					tcpArray_ch[i] = *X;
				}
			}
			//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
			outputTcp(tcpArray_ch, 0);
			for (int i = 0; i < 10; i++)
			{	// int <= char �迭��ȯ
				tcpArray[i] = (int)tcpArray_ch[i];
			}
			judge.CheckYourTurn(tcpArray);		//��ȿ�� ����
			if (judge.GetFinish())
			{	//���� ���������� �޾Ҵµ� ������ ������
				for (int i = 0; i < 10; i++)
				{	// int <= char �迭��ȯ
					tcpArray[i] = (int)tcpArray_ch[i];
				}

				if (judge.GetMyVic())
				{	//�¸������� ������.
					tcpArray_ch[0] = 103;
					tcpArray_ch[1] = -1;
					cout << "�¸� ������ �����մϴ�(103, -1)" << endl;
					send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
					//�й������ �޾ƾ� ��.
					outputTcp(tcpArray_ch, 1);
					cout << "���� �й������ �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�й� ������ �޾ҽ��ϴ�. ��������." << endl;
							break;
						}
						else
						{
							cout << "���� ���� �й�����Դϴ�." << endl;
							break;
						}
					}
					else
					{
						cout << "��밡 �й������ ������ �ʾҽ��ϴ�." << endl;
						cout << "���� ����." << endl;
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//�й������ ������.
					tcpArray_ch[0] = 104;
					tcpArray_ch[1] = -1;
					send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
					//�¸������� �޾ƾ���.
					outputTcp(tcpArray_ch, 1);
					cout << "���� �¸������� �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�¸� ������ �޾ҽ��ϴ�. ��������." << endl;
							break;
						}
						else
						{
							cout << "���� ���� �¸������Դϴ�." << endl;
							break;
						}
					}
					else
					{
						cout << "��밡 �¸������� ������ �ʾҽ��ϴ�." << endl;
						cout << "���� ����." << endl;
						break;
					}
				}
				else
				{	//���º�
					cout << "�����ϴ�.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
					outputTcp(tcpArray_ch, 1);
					break;
				}
			}
			strategy01.receive(tcpArray[1]);		//����� �� �Է�

			T = strategy01.send();					//�˰��� ����
			tcpArray[1] = T;					//���� ���� tcp_int�迭�� ��´�
			tcpArray_ch[1] = (char)tcpArray[1];	//int -> char �迭��ȯ
			send(TcpSoc, tcpArray_ch, 3, 0);	//TCP����
			outputTcp(tcpArray_ch, 1);
			judge.CheckMyTurn(T);				//��ȿ�� ����
			if (judge.GetFinish())
			{	//���� ���� ���´µ� ������ ������

				if (judge.GetMyVic())
				{	//������� �й������ �޾ƾ���.
					cout << "���� �й������ �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�й� ������ �޾ҽ��ϴ�. �¸����� ������ ��������." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "��밡 �й� ����(104, -1)�� ������ �ʾҽ��ϴ�." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							cout << "�¸� ����(103, -1)�� ������ ���� ����." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "��밡 �й� ����(104, -1)�� ������ �ʾҽ��ϴ�." << endl;
						tcpArray_ch[0] = 103;
						tcpArray_ch[1] = -1;
						cout << "�¸� ����(103, -1)�� ������ ���� ����." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//������� �¸������� �޾ƾ���.
					cout << "���� �¸������� �������մϴ�...(�����)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP����
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP�� ����
							tcpArray_ch[i] = *X;
						}
					}
					//��밡 TCP������ �����Ұ��, (��밡 send �������ؼ� �������)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "�¸� ������ �޾ҽ��ϴ�. �й���� ������ ��������." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "��밡 �¸� ����(103, -1)�� ������ �ʾҽ��ϴ�." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							cout << "�й� ����(104, -1)�� ������ ���� ����." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "��밡 �¸� ����(103, -1)�� ������ �ʾҽ��ϴ�." << endl;
						tcpArray_ch[0] = 104;
						tcpArray_ch[1] = -1;
						cout << "�й� ����(104, -1)�� ������ ���� ����." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//�й� �÷��� ����
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else
				{	//���º�
					cout << "�����ϴ�.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//�¸� �÷��� ����
					outputTcp(tcpArray_ch, 1);
				}
				break;
			}
		}

		break;	//case 1 ����
	}
	/* �� �κ� ���� ���� */
	cout << endl << "���α׷��� �����մϴ�." << endl;

	closesocket(TcpSoc);
	WSACleanup();
	delete X;
	return 0;
}

void outputTcp(char* array_ch, bool my)
{
	int array[10];
	if (my)cout << "tcp ���� �� : ";
	else cout << "tcp ���� �� : ";
	for (int i = 0; i < 10; i++)
	{
		array[i] = (int)array_ch[i];
		cout << array[i] << " ";
		if (array[i] == -1) break;
	}
	cout << endl;
}