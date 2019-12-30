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
#define SERVER_IP "192.168.219.196"		//상대가 서버일경우 ip작성.
void outputTcp(char* array_ch, bool my);
//tcp통신된 값을 출력해주는 함수.

int main(void)
{
	WSADATA wsaData;
	SOCKET ServSoc;
	SOCKET TcpSoc;
	SOCKADDR_IN ServSocAddr = { 0, };
	SOCKADDR_IN TcpSocAddr = { 0, };
	gameTarget target(99);				//목표값 class 선언과 동시에 후수일 때 보낼 목표값 설정(constructor)
	srand((unsigned)time(NULL));		//랜덤값 도출을 위한 전처리
	bool tcpOption;						//서버모드1,	클라이언트0
	bool gameMode;						//후수1,		선수0
	bool output = 0;					//출력 설정
	bool output_judge = 1;				//judge클래스 출력 모드
	int tcpArray[10] = { 0, };			//tcp 값을 담는 int 배열
	char tcpArray_ch[10] = { 0, };		//tcp 값을 담는 char 배열
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << ("원속 생성 실패!");
		exit(1);
	}//원속 초기화 성공 시 0 반환, 이 외의 경우엔 실패		
	cout << "<< 고급프로그래밍 Number Counting Game 프로젝트 2조 >>" << endl << endl;
	cout << "TCP/IP 통신 모드를 설정하십시오(0.client, 1.server) : ";
	cin >> tcpOption;					//TCP모드 선택.
	if (tcpOption)
	{	//서버 전처리
		cout << endl << "server모드 입니다." << endl;
		ServSoc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//소켓 설정 -> 32bit 주소 체계, 연결 지향성, TCP방식 사용을 의미
		ServSocAddr.sin_family = AF_INET;					//IPv4 protocol
		ServSocAddr.sin_port = htons(PORT);					//Port 번호 설정
		ServSocAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//현재 프로그램이 구동되는 컴퓨터의 IP주소로 설정해준다.
		bind(ServSoc, (SOCKADDR*)&ServSocAddr, sizeof(ServSocAddr));//24~30에서 설정한 소켓의 주소정보를 소켓에 묶어준다.
		listen(ServSoc, SOMAXCONN);							//SOMAXCONN은 최대 접속 수
		int TcpSoc_size = sizeof(TcpSocAddr);
		cout << "server모드 전처리 완료." << endl << endl;
		cout << "클라이언트 응답 대기중..." << endl;
		TcpSoc = accept(ServSoc, (SOCKADDR*)&TcpSocAddr, &TcpSoc_size);//cnt 소켓 정보 담기. 접속요청을 대기.
		cout << "클라이언트 응답 확인." << endl << endl;
	}
	else
	{	//클라이언트 전처리
		cout << endl << "client모드 입니다." << endl;
		TcpSoc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		TcpSocAddr.sin_family = AF_INET;
		TcpSocAddr.sin_port = htons(PORT);
		TcpSocAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
		cout << "client모드 전처리 완료." << endl << endl;
		cout << "서버 응답 대기중..." << endl;
		connect(TcpSoc, (SOCKADDR*)&TcpSocAddr, sizeof(TcpSocAddr));	//accept와 짝임.
		cout << "서버 응답 확인." << endl << endl;
	}
	/* 윗 부분 TCP 통신 전처리 */

	cout << "순서를 선택하십시오(0.선수, 1.후수) : ";
	cin >> gameMode;
	gameCount count01;					//알고리즘 class
	randomCount random01;				//랜덤 class (찬스 사용가능, 거리 5이내의 목표값은 먹음)
	strategy strategy01;				//희준형 알고리즘
	Judge judge;
	judge.readOutput(output_judge);		//출력모드 설정.
	int T = 1;							//통신값인 매개변수.
	char* X = NULL;						//통신할 때 임시포인터.
	X = new char;						//
	int len = 0;						//수신값의 길이를 담을 변수.
	int j = 0;							//target 넘길때 꼭 필요한 index.

	switch (gameMode)				//선택받은 모드에 따라
	{
	case 0:		//count가 선수인 케이스
		cout << "선수로 게임을 시작합니다." << endl << endl;
		len = recv(TcpSoc, tcpArray_ch, 10, 0);		//TCP목표값 수신
		if (len == 1)
		{
			*X = 0;
			for (int i = 1; *X != -1; i++)
			{
				recv(TcpSoc, X, 10, 0);		//TCP값 수신
				tcpArray_ch[i] = *X;
			}
		}
		//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
		outputTcp(tcpArray_ch, 0);

		for (int i = 0; i < 10; i++)
		{	// int <= char 배열변환
			tcpArray[i] = (int)tcpArray_ch[i];
		}
		target.receive(tcpArray);				//target에 상대의목표값 입력
		target.select();						//그중 선택	목표값을 선택
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
		{	// char <= int 배열변환
			tcpArray_ch[i] = (char)tcpArray[i];
		}

		send(TcpSoc, tcpArray_ch, target.getNum() + 3, 0);	//TCP목표값 전송
		outputTcp(tcpArray_ch, 1);
		strategy01.readTarget(target.getNum(), target.getPtrTarget());	//알고리즘 에 목표값 입력
		judge.SetGoalValue_First(target.getNum(), target.getPtrTarget());//judge 에 목표값 입력 정보전달
		strategy01.map_first();											//희준이형 알고리즘 함수.

		for (int i = 0; i < 10; i++)
		{	//tcp배열 초기화
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
		{	//주고받는 한 사이클. array는 (101, 0, -1)상태
			T = strategy01.send();					//알고리즘값 도출
			tcpArray[1] = T;					//보낼 값을 tcp_int배열에 담는다
			tcpArray_ch[1] = (char)tcpArray[1];	//int -> char 배열변환
			send(TcpSoc, tcpArray_ch, 3, 0);	//TCP전송
			outputTcp(tcpArray_ch, 1);
			judge.CheckMyTurn(T);				//유효값 판정
			if (judge.GetFinish())
			{	//내가 값을 보냈는데 게임이 끝나면

				if (judge.GetMyVic())
				{	//상대한테 패배사인을 받아야함.
					cout << "상대는 패배 사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "패배 사인을 받았습니다. 승리 사인 보내고 게임종료." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "상대가 패배 사인(104, -1)을 보내지 않았습니다." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							cout << "승리 사인(103, -1)을 보내고 게임 종료." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "상대가 패배 사인(104, -1)을 보내지 않았습니다." << endl;
						tcpArray_ch[0] = 103;
						tcpArray_ch[1] = -1;
						cout << "승리 사인(103, -1)을 보내고 게임 종료." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//상대한테 승리사인을 받아야함.
					cout << "상대는 승리사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "승리 사인을 받았습니다. 패배사인 보내고 게임종료." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "상대가 승리 사인(103, -1)을 보내지 않았습니다." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							cout << "패배 사인(104, -1)을 보내고 게임 종료." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "상대가 승리 사인(103, -1)을 보내지 않았습니다." << endl;
						tcpArray_ch[0] = 104;
						tcpArray_ch[1] = -1;
						cout << "패배 사인(104, -1)을 보내고 게임 종료." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else
				{	//무승부
					cout << "비겼습니다.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
					outputTcp(tcpArray_ch, 1);
				}
				break;
			}

			len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
			if (len == 1)
			{
				*X = 0;
				for (int i = 1; *X != -1; i++)
				{
					recv(TcpSoc, X, 10, 0);		//TCP값 수신
					tcpArray_ch[i] = *X;
				}
			}
			//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
			outputTcp(tcpArray_ch, 0);
			for (int i = 0; i < 10; i++)
			{	// int <= char 배열변환
				tcpArray[i] = (int)tcpArray_ch[i];
			}
			judge.CheckYourTurn(tcpArray);		//유효값 판정
			if (judge.GetFinish())
			{	//내가 마지막값을 받았는데 게임이 끝나면
				for (int i = 0; i < 10; i++)
				{	// int <= char 배열변환
					tcpArray[i] = (int)tcpArray_ch[i];
				}

				if (judge.GetMyVic())
				{	//승리사인을 보낸다.
					tcpArray_ch[0] = 103;
					tcpArray_ch[1] = -1;
					cout << "승리 사인을 전송합니다(103, -1)" << endl;
					send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
					//패배사인을 받아야 함.
					outputTcp(tcpArray_ch, 1);
					cout << "상대는 패배사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "패배 사인을 받았습니다. 게임종료." << endl;
							break;
						}
						else
						{
							cout << "옳지 않은 패배사인입니다." << endl;
							break;
						}
					}
					else
					{
						cout << "상대가 패배사인을 보내지 않았습니다." << endl;
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//패배사인을 보낸다.
					tcpArray_ch[0] = 104;
					tcpArray_ch[1] = -1;
					send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
					//승리사인을 받아야함.
					outputTcp(tcpArray_ch, 1);
					cout << "상대는 승리사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "승리 사인을 받았습니다. 게임종료." << endl;
							break;
						}
						else
						{
							cout << "옳지 않은 승리사인입니다." << endl;
							break;
						}
					}
					else
					{
						cout << "상대가 승리사인을 보내지 않았습니다." << endl;
						break;
					}
				}
				else
				{	//무승부
					cout << "비겼습니다.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
					outputTcp(tcpArray_ch, 1);
					break;
				}
			}
			strategy01.receive(tcpArray[1]);		//상대의 수 입력
		}

		break;	//case 0 종료

	case 1:		//count가 후수인 케이스
		cout << "후수로 게임을 시작합니다." << endl << endl;
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
		{	// char <= int 배열변환
			tcpArray_ch[i] = (char)tcpArray[i];
		}

		send(TcpSoc, tcpArray_ch, target.getNum() + 3, 0);	//TCP목표값 전송
		outputTcp(tcpArray_ch, 1);
		len = recv(TcpSoc, tcpArray_ch, 10, 0);				//TCP목표값 수신
		if (len == 1)
		{
			*X = 0;
			for (int i = 1; *X != -1; i++)
			{
				recv(TcpSoc, X, 10, 0);		//TCP값 수신
				tcpArray_ch[i] = *X;
			}
		}
		//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
		outputTcp(tcpArray_ch, 0);

		for (int i = 0; i < 10; i++)
		{	// int <= char 배열변환
			tcpArray[i] = (int)tcpArray_ch[i];
		}
		target.receive(tcpArray);				//target에 상대의목표값 입력
		judge.SetGoalValue_Second(tcpArray);	//judge에 상대의 목표값을 검증(입력)
		strategy01.readTarget(target.getNum(), target.getPtrTarget());	//알고리즘에 목표값 입력
		strategy01.map_second();											//희준이형 알고리즘 함수.

		for (int i = 0; i < 10; i++)
		{	//tcp배열 초기화
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
			len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
			if (len == 1)
			{
				*X = 0;
				for (int i = 1; *X != -1; i++)
				{
					recv(TcpSoc, X, 10, 0);		//TCP값 수신
					tcpArray_ch[i] = *X;
				}
			}
			//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
			outputTcp(tcpArray_ch, 0);
			for (int i = 0; i < 10; i++)
			{	// int <= char 배열변환
				tcpArray[i] = (int)tcpArray_ch[i];
			}
			judge.CheckYourTurn(tcpArray);		//유효값 판정
			if (judge.GetFinish())
			{	//내가 마지막값을 받았는데 게임이 끝나면
				for (int i = 0; i < 10; i++)
				{	// int <= char 배열변환
					tcpArray[i] = (int)tcpArray_ch[i];
				}

				if (judge.GetMyVic())
				{	//승리사인을 보낸다.
					tcpArray_ch[0] = 103;
					tcpArray_ch[1] = -1;
					cout << "승리 사인을 전송합니다(103, -1)" << endl;
					send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
					//패배사인을 받아야 함.
					outputTcp(tcpArray_ch, 1);
					cout << "상대는 패배사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "패배 사인을 받았습니다. 게임종료." << endl;
							break;
						}
						else
						{
							cout << "옳지 않은 패배사인입니다." << endl;
							break;
						}
					}
					else
					{
						cout << "상대가 패배사인을 보내지 않았습니다." << endl;
						cout << "게임 종료." << endl;
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//패배사인을 보낸다.
					tcpArray_ch[0] = 104;
					tcpArray_ch[1] = -1;
					send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
					//승리사인을 받아야함.
					outputTcp(tcpArray_ch, 1);
					cout << "상대는 승리사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);
					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "승리 사인을 받았습니다. 게임종료." << endl;
							break;
						}
						else
						{
							cout << "옳지 않은 승리사인입니다." << endl;
							break;
						}
					}
					else
					{
						cout << "상대가 승리사인을 보내지 않았습니다." << endl;
						cout << "게임 종료." << endl;
						break;
					}
				}
				else
				{	//무승부
					cout << "비겼습니다.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
					outputTcp(tcpArray_ch, 1);
					break;
				}
			}
			strategy01.receive(tcpArray[1]);		//상대의 수 입력

			T = strategy01.send();					//알고리즘값 도출
			tcpArray[1] = T;					//보낼 값을 tcp_int배열에 담는다
			tcpArray_ch[1] = (char)tcpArray[1];	//int -> char 배열변환
			send(TcpSoc, tcpArray_ch, 3, 0);	//TCP전송
			outputTcp(tcpArray_ch, 1);
			judge.CheckMyTurn(T);				//유효값 판정
			if (judge.GetFinish())
			{	//내가 값을 보냈는데 게임이 끝나면

				if (judge.GetMyVic())
				{	//상대한테 패배사인을 받아야함.
					cout << "상대는 패배사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 104)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "패배 사인을 받았습니다. 승리사인 보내고 게임종료." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "상대가 패배 사인(104, -1)을 보내지 않았습니다." << endl;
							tcpArray_ch[0] = 103;
							tcpArray_ch[1] = -1;
							cout << "승리 사인(103, -1)을 보내고 게임 종료." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "상대가 패배 사인(104, -1)을 보내지 않았습니다." << endl;
						tcpArray_ch[0] = 103;
						tcpArray_ch[1] = -1;
						cout << "승리 사인(103, -1)을 보내고 게임 종료." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else if (judge.GetYourVic())
				{	//상대한테 승리사인을 받아야함.
					cout << "상대는 승리사인을 보내야합니다...(대기중)" << endl;
					len = recv(TcpSoc, tcpArray_ch, 10, 0);	//TCP수신
					if (len == 1)
					{
						*X = 0;
						for (int i = 1; *X != -1; i++)
						{
							recv(TcpSoc, X, 10, 0);		//TCP값 수신
							tcpArray_ch[i] = *X;
						}
					}
					//상대가 TCP전송을 각각할경우, (상대가 send 여러번해서 보낼경우)
					outputTcp(tcpArray_ch, 0);

					if (tcpArray_ch[0] == 103)
					{
						if (tcpArray_ch[1] == -1)
						{
							cout << "승리 사인을 받았습니다. 패배사인 보내고 게임종료." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
						else
						{
							cout << "상대가 승리 사인(103, -1)을 보내지 않았습니다." << endl;
							tcpArray_ch[0] = 104;
							tcpArray_ch[1] = -1;
							cout << "패배 사인(104, -1)을 보내고 게임 종료." << endl;
							send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
							outputTcp(tcpArray_ch, 1);
							break;
						}
					}
					else
					{
						cout << "상대가 승리 사인(103, -1)을 보내지 않았습니다." << endl;
						tcpArray_ch[0] = 104;
						tcpArray_ch[1] = -1;
						cout << "패배 사인(104, -1)을 보내고 게임 종료." << endl;
						send(TcpSoc, tcpArray_ch, 2, 0);	//패배 플래그 전송
						outputTcp(tcpArray_ch, 1);
						break;
					}
				}
				else
				{	//무승부
					cout << "비겼습니다.";
					send(TcpSoc, tcpArray_ch, 2, 0);	//승리 플래그 전송
					outputTcp(tcpArray_ch, 1);
				}
				break;
			}
		}

		break;	//case 1 종료
	}
	/* 윗 부분 게임 진행 */
	cout << endl << "프로그램을 종료합니다." << endl;

	closesocket(TcpSoc);
	WSACleanup();
	delete X;
	return 0;
}

void outputTcp(char* array_ch, bool my)
{
	int array[10];
	if (my)cout << "tcp 전송 값 : ";
	else cout << "tcp 수신 값 : ";
	for (int i = 0; i < 10; i++)
	{
		array[i] = (int)array_ch[i];
		cout << array[i] << " ";
		if (array[i] == -1) break;
	}
	cout << endl;
}