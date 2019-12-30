#include <iostream>
#include "Judge.h"
using namespace std;

Judge::Judge() { // 생성자
	MyTotalValue = 0;
	MyPickValue = 0;
	YourPickValue = 0;
	YourTotalValue = 0;
	GoalNum = 0;
	MyGoal = 0;
	YourGoal = 0;
	MyChance = 0;
	YourChance = 0;
	MyVic = 0;
	YourVic = 0;
	output = 0;
	finish = 0;
	NumOfGame = 0;
	for (int i = 0; i < 7; i++) {
		MyGoalVal[i] = 0;
		YourGoalVal[i] = 0;
	}
	delete[] GoalValue;
	GoalValue = NULL;
}
void Judge::SetGoalValue_First(int Valuenum, int Value[]) { // 선수일 때 내가 선택한 목표값과 개수를 저장
	GoalNum = Valuenum;
	GoalValue = new int[Valuenum];
	for (int i = 0; i < Valuenum; i++)
		GoalValue[i] = Value[i]; // 목표값 저장

		///////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < GoalNum; i++) { // 목표값 순차 정렬
		for (int j = i + 1; j < GoalNum; j++) {
			if (GoalValue[i] > GoalValue[j]) { // 앞쪽 원소가 더 크면 서로 교환
				int swap = GoalValue[i];
				GoalValue[i] = GoalValue[j];
				GoalValue[j] = swap;
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////

	if (output)cout << endl << "<< 목표값은 ";
	for (int j = 0; j < GoalNum; j++)
		if (output)cout << GoalValue[j] << ", ";
	if (output)cout << "으로 총 " << GoalNum << "개 입니다. >>" << endl << endl; // 목표값에 대한 출력

}
void Judge::SetGoalValue_Second(int Value[]) { // 후수일 때 상대가 선택한 목표값과 개수를 저장(tcp)
	if (Value[0] == 101) { // 유효성 검사 1
		GoalNum = Value[1];
		GoalValue = new int[Value[1]];
		if (Value[GoalNum + 2] == -1) { // 유효성 검사 1
			for (int i = 0; i < GoalNum; i++)
			{
				if ((Value[i + 2] < 31) || (Value[i + 2] > 99)) {
					cout << "상대가 보낸 " << i + 1 << "번째 목표값 " << Value[i + 2] << "이 31이상 100 미만의 값이 아닙니다. ";
					exit(1);
				}
				else
					GoalValue[i] = Value[i + 2];
			}
		} // 목표값 저장
		else {
			cout << "데이터 전달의 마지막 값이 " << Value[2] << " 으로 -1 이 아닙니다.";
			exit(1);
		}
	}
	else {
		cout << "데이터 전달의 시작값이 " << Value[0] << " 으로 101 이/가 아닙니다.";
		exit(1);
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < GoalNum; i++) { // 목표값 정렬
		for (int j = i + 1; j < GoalNum; j++) {
			if (GoalValue[i] > GoalValue[j]) { // 앞쪽 원소가 더 크면 서로 교환
				int swap = GoalValue[i];
				GoalValue[i] = GoalValue[j];
				GoalValue[j] = swap;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	cout << "<< 목표값은 ";
	for (int j = 0; j < GoalNum; j++)
		cout << GoalValue[j] << ", ";
	cout << "으로 총 " << GoalNum << "개 입니다. >>" << endl << endl; // 목표값에 대한 출력

}
void Judge::CheckMyTurn(int Value) {  // 내가 보낼 값에 대해 유효값검사, 찬스 사용 여부 확인, 득점 여부 확인, 출력
	if (YourGoal > MyGoal) {
		if (MyChance != -1)
			MyChance = 1;
	} // 나의 찬스 여부 확인; 찬스를 얻었을 경우 1; 찬스를 이미 썻을 경우 -1; 
	if (NumOfGame == 0) { // 값을 전달한 횟수가 0이다 => 선수로써 값을 처음 보내는 경우 (이때, 후수로써 값을 처음 보내는 경우는 1이다)
		MyTotalValue = Value;
		MyPickValue = Value;
		if (MyPickValue < 1 || MyPickValue > 5) { // 유효성 검사 2
			cout << "내가 선택한 값이 1과 5 사이의 값이 아닙니다." << endl;
			cout << "내가 보내준 값 : " << MyTotalValue << " , 내가 선택한 값 : " << MyPickValue;
			exit(1);
		}
	}
	else { // 평범한 경우 => 내가 보낼 값의 유효성 검사
		MyTotalValue = Value;
		MyPickValue = Value - YourTotalValue;
		if (MyPickValue < 1 || MyPickValue > 5) { // 유효성 검사 2
			cout << "내가 선택한 값이 1과 5 사이의 값이 아닙니다.";
			cout << "내가 보내준 값 : " << MyTotalValue << " , 내가 선택한 값 : " << MyPickValue;
			exit(1);
		}
		if (NumOfGame > 1) { // 값을 처음 보낼때 다음 유효성 검사는 해당하지 않음
			if ((MyPickValue < YourPickValue - 1) || (MyPickValue > YourPickValue + 1)) { // 유효성 검사 3
				if (MyChance == 1) { // 찬스가 있을 시 유효성을 벗어났으므로 찬스를 사용한 것으로 간주함
					if (output)cout << " << 내가 Chance를 사용하였습니다. >>" << endl;
					MyChance = -1; // 찬스를 사용했다는 표식
				}
				else { // 찬스가 없을 시
					cout << "내가 선택한 값이 상대가 선택한 값의 -1, +0, +1을 한 값이 아닙니다.";
					cout << "내가 보내준 값   : " << MyTotalValue << " (( 내가 선택한 값 : " << MyPickValue << " ))" << endl;
					cout << "상대가 보내준 값 : " << YourTotalValue << " (( 상대가 선택한 값 : " << YourPickValue << " ))" << endl;
					exit(1);
				}
			}
		}
	}
	NumOfGame++; // 유효성 검사를 마친 값을 보낼 것이므로 전달 횟수를 1 증가시킴

	//cout << "나의 차례입니다." << endl;
	if (output)cout << "내가 보내준 값   : " << MyTotalValue << " (( 내가 선택한 값 : " << MyPickValue << " ))" << endl;

	int i = 0;
	while (i < GoalNum) { // 내가 보내는 값이 득점을 하는지를 모든 목표값에 대해 확인한다.
		if ((YourTotalValue < GoalValue[i]) && (MyTotalValue >= GoalValue[i])) {
			MyGoal += 1;
			MyGoalVal[i] = GoalValue[i];
			if (output)cout << "내가 목표값 " << GoalValue[i] << "를 획득하셨습니다. ( 나의 현재 점수 : " << MyGoal << " 점)" << endl << endl; // 나의 득점 출력
			if (i == GoalNum - 1) { // 만약 마지막 목표값을 획득한다면 게임이 종료된다.
				finish = 1;		//게임 끝을 의미
				if (output)cout << "내가 마지막 목표값을 획득하였습니다. 게임을 종료합니다." << endl;
				if (output)cout << "(나의 점수 : " << MyGoal << " 점)" << "(상대의 점수 : " << YourGoal << " 점)" << endl;
				if (MyGoal == YourGoal) { // 만약 점수가 같다면 최종 점수를 비교해줌
					int YourFinGoal = 0; //상대의 최종 점수
					int MyFinalGoal = 0; // 나의 최종 점수

					for (int j = 0; j < 7; j++) {
						YourFinGoal += YourGoalVal[j];
						MyFinalGoal += MyGoalVal[j];
					}
					if (MyFinalGoal < YourFinGoal) { // 상대의 최종 점수가 높을 시 상대가 승리
						if (output)
						{
							cout << "상대가 게임에서 승리하였습니다. " << endl;
							cout << "상대 총 목표값 합계 : " << YourFinGoal << " " << endl;
							cout << "나의 총 목표값 합계 : " << MyFinalGoal << " " << endl;
						}
						YourVic = 1;
					}
					else if (MyFinalGoal == YourFinGoal) { // 최종 점수가 같을 시 무승부
						if (output)
						{
							cout << "게임 결과는 무승부입니다. " << endl;
							cout << "상대 총 목표값 합계 : " << YourFinGoal << " " << endl;
							cout << "나의 총 목표값 합계 : " << MyFinalGoal << " " << endl;
						}
						MyVic = 0;
						YourVic = 0;
					}
					else { // 나의 최종 점수가 높을 시 나의 승리
						if (output)
						{
							cout << "내가 게임에서 승리하였습니다. " << endl;
							cout << "상대 총 목표값 합계 : " << YourFinGoal << " " << endl;
							cout << "나의 총 목표값 합계 : " << MyFinalGoal << " " << endl;
						}
						MyVic = 1;
					}
				}
				else if (MyGoal > YourGoal)
				{
					MyVic = 1;
				}
				else if (MyGoal < YourGoal)
				{
					YourVic = 1;
				}
				else
				{
					cout << "승점 계산 에러." << endl;
				}
			}
		}
		i++;
	}
}
void Judge::CheckYourTurn(int Value[]) { // 상대가 보낸 값에 대해 유효성검사, 찬스 사용 여부 확인, 득점 여부 확인, 출력
	if (MyGoal > YourGoal) {
		if (YourChance != -1)
			YourChance = 1;
	} // 상대의 찬스 여부 확인; 찬스를 얻었을 경우 1; 찬스를 이미 썻을 경우 -1; 
	if (Value[0] != 101) { // 유효성 검사 1
		cout << "데이터 전달의 시작값이 " << Value[0] << " 으로 101 이/가 아닙니다.";
		exit(1);
	}
	if (Value[2] != -1) { // 유효성 검사 1
		cout << "데이터 전달의 마지막 값이 " << Value[2] << " 으로 -1 이 아닙니다.";
		exit(1);
	}
	if (NumOfGame == 0) { // 값을 전달한 값이 0이다 => 상대가 선수로써 값을 먼저 보낸 경우
		YourTotalValue = Value[1];
		YourPickValue = Value[1];
		if (YourPickValue < 1 || YourPickValue > 5) { // 유효성 검사 2
			cout << "상대가 선택한 값이 1과 5 사이의 값이 아닙니다.";
			exit(1);
		}
	}
	else { // 평범한 경우 => 상대가 보낸 값의 유효성 검사
		YourTotalValue = Value[1];
		YourPickValue = Value[1] - MyTotalValue;
		if (YourPickValue < 1 || YourPickValue > 5) { // 유효성 검사 2
			cout << "상대가 선택한 값이 1과 5 사이의 값이 아닙니다.";
			exit(1);
		}
		if (NumOfGame > 1) { // 값을 처음 보낼때 다음 유효성 검사는 해당하지 않음
			if ((YourPickValue < MyPickValue - 1) || (YourPickValue > MyPickValue + 1)) { // 유효성 검사 3
				if (YourChance == 1) { // 찬스가 있을 시 유효성을 벗어났으므로 찬스를 사용한 것으로 간주함
					if (output)cout << " << 상대가 Chance를 사용하였습니다. >>" << endl;
					YourChance = -1; // 상대가 찬스를 사용한 표식
				}
				else { // 찬스가 없을시
					cout << "상대가 선택한 값이 내가 선택한 값의 -1, +0, +1을 한 값이 아닙니다." << endl;
					cout << "내가 보내준 값   : " << MyTotalValue << " (( 내가 선택한 값 : " << MyPickValue << " ))" << endl;
					cout << "상대가 보내준 값 : " << YourTotalValue << " (( 상대가 선택한 값 : " << YourPickValue << " ))" << endl;
					cout << " <<<< 실격 >>>> " << endl;
					exit(1);
				}
			}
		}
	}

	NumOfGame++; // 상대가 값을 나에게 보냈으므로 전달 횟수 1 증가 

	//cout << "상대의 차례입니다." << endl;
	if (output)cout << "상대가 보내준 값 : " << YourTotalValue << " (( 상대가 선택한 값 : " << YourPickValue << " ))" << endl;

	for (int i = 0; i < GoalNum; i++) { // 상대가 보낸 값이 득점을 하는지를 모든 목표값에 대해 확인한다.

		if ((MyTotalValue < GoalValue[i]) && (YourTotalValue >= GoalValue[i])) {
			YourGoal += 1;
			YourGoalVal[i] = GoalValue[i];
			if (output)cout << "상대가 목표값 " << GoalValue[i] << "를 획득하셨습니다. ( 상대의 현재 점수 : " << YourGoal << " 점)" << endl << endl; // 상대의 득점 출력

			if (i == GoalNum - 1) { // 만약 마지막 목표값을 획득한다면 게임이 종료된다.
				finish = 1;
				if (output)cout << "상대가 마지막 목표값을 획득하였습니다. 게임이 종료됩니다." << endl;
				if (output)cout << "(나의 점수 : " << MyGoal << " 점)" << "(상대의 점수 : " << YourGoal << " 점)" << endl;

				if (MyGoal == YourGoal) { // 점수가 같을 시 최종 점수 비교

					if (output)cout << "게임 결과는 무승부입니다. " << endl;
					int YourFinGoal = 0; //상대의 최종 점수
					int MyFinalGoal = 0; // 나의 최종 점수

					for (int j = 0; j < 7; j++) {
						YourFinGoal += YourGoalVal[j];
						MyFinalGoal += MyGoalVal[j];
					}
					if (MyFinalGoal < YourFinGoal) { // 상대의 최종 점수가 높을 시 상대가 승리
						if (output)
						{
							cout << "상대가 게임에서 승리하였습니다. " << endl;
							cout << "상대 총 목표값 합계 : " << YourFinGoal << " " << endl;
							cout << "나의 총 목표값 합계 : " << MyFinalGoal << " " << endl;
						}
						YourVic = 1;
					}
					else if (MyFinalGoal == YourFinGoal) { // 최종 점수가 같을 시 무승부
						if (output)
						{
							cout << "게임 결과는 무승부입니다. " << endl;
							cout << "상대 총 목표값 합계 : " << YourFinGoal << " " << endl;
							cout << "나의 총 목표값 합계 : " << MyFinalGoal << " " << endl;
						}
						MyVic = 0;
						YourVic = 0;
					}
					else { // 나의 최종 점수가 높을 시 나의 승리
						if (output)
						{
							cout << "내가 게임에서 승리하였습니다. " << endl;
							cout << "상대 총 목표값 합계 : " << YourFinGoal << " " << endl;
							cout << "나의 총 목표값 합계 : " << MyFinalGoal << " " << endl;
						}
						MyVic = 1;
					}

				}
				else if (MyGoal > YourGoal)
				{
					MyVic = 1;
				}
				else if (MyGoal < YourGoal)
				{
					YourVic = 1;
				}
				else
				{
					cout << "승점 계산 에러." << endl;
				}
			}
		}
	}
}
void Judge::readOutput(bool output_)
{
	output = output_;
}
int Judge::GetMyVic() { // 나의 승리 여부를 불러옴. 1일 경우 나의 승리, 2일 경우 무승부
	return MyVic;
}
int Judge::GetYourVic() { // 상대의 승리 여부를 불러옴. 1일 경우 나의 패배, 2일 경우 무승부
	return YourVic;
}
bool Judge::GetFinish()
{
	return finish;
}
Judge::~Judge() { // 소멸자
	delete[] GoalValue;
	GoalValue = NULL;
}
