#include <iostream>
#include "Judge.h"
using namespace std;

Judge::Judge() { // ������
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
void Judge::SetGoalValue_First(int Valuenum, int Value[]) { // ������ �� ���� ������ ��ǥ���� ������ ����
	GoalNum = Valuenum;
	GoalValue = new int[Valuenum];
	for (int i = 0; i < Valuenum; i++)
		GoalValue[i] = Value[i]; // ��ǥ�� ����

		///////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < GoalNum; i++) { // ��ǥ�� ���� ����
		for (int j = i + 1; j < GoalNum; j++) {
			if (GoalValue[i] > GoalValue[j]) { // ���� ���Ұ� �� ũ�� ���� ��ȯ
				int swap = GoalValue[i];
				GoalValue[i] = GoalValue[j];
				GoalValue[j] = swap;
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////

	if (output)cout << endl << "<< ��ǥ���� ";
	for (int j = 0; j < GoalNum; j++)
		if (output)cout << GoalValue[j] << ", ";
	if (output)cout << "���� �� " << GoalNum << "�� �Դϴ�. >>" << endl << endl; // ��ǥ���� ���� ���

}
void Judge::SetGoalValue_Second(int Value[]) { // �ļ��� �� ��밡 ������ ��ǥ���� ������ ����(tcp)
	if (Value[0] == 101) { // ��ȿ�� �˻� 1
		GoalNum = Value[1];
		GoalValue = new int[Value[1]];
		if (Value[GoalNum + 2] == -1) { // ��ȿ�� �˻� 1
			for (int i = 0; i < GoalNum; i++)
			{
				if ((Value[i + 2] < 31) || (Value[i + 2] > 99)) {
					cout << "��밡 ���� " << i + 1 << "��° ��ǥ�� " << Value[i + 2] << "�� 31�̻� 100 �̸��� ���� �ƴմϴ�. ";
					exit(1);
				}
				else
					GoalValue[i] = Value[i + 2];
			}
		} // ��ǥ�� ����
		else {
			cout << "������ ������ ������ ���� " << Value[2] << " ���� -1 �� �ƴմϴ�.";
			exit(1);
		}
	}
	else {
		cout << "������ ������ ���۰��� " << Value[0] << " ���� 101 ��/�� �ƴմϴ�.";
		exit(1);
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < GoalNum; i++) { // ��ǥ�� ����
		for (int j = i + 1; j < GoalNum; j++) {
			if (GoalValue[i] > GoalValue[j]) { // ���� ���Ұ� �� ũ�� ���� ��ȯ
				int swap = GoalValue[i];
				GoalValue[i] = GoalValue[j];
				GoalValue[j] = swap;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	cout << "<< ��ǥ���� ";
	for (int j = 0; j < GoalNum; j++)
		cout << GoalValue[j] << ", ";
	cout << "���� �� " << GoalNum << "�� �Դϴ�. >>" << endl << endl; // ��ǥ���� ���� ���

}
void Judge::CheckMyTurn(int Value) {  // ���� ���� ���� ���� ��ȿ���˻�, ���� ��� ���� Ȯ��, ���� ���� Ȯ��, ���
	if (YourGoal > MyGoal) {
		if (MyChance != -1)
			MyChance = 1;
	} // ���� ���� ���� Ȯ��; ������ ����� ��� 1; ������ �̹� ���� ��� -1; 
	if (NumOfGame == 0) { // ���� ������ Ƚ���� 0�̴� => �����ν� ���� ó�� ������ ��� (�̶�, �ļ��ν� ���� ó�� ������ ���� 1�̴�)
		MyTotalValue = Value;
		MyPickValue = Value;
		if (MyPickValue < 1 || MyPickValue > 5) { // ��ȿ�� �˻� 2
			cout << "���� ������ ���� 1�� 5 ������ ���� �ƴմϴ�." << endl;
			cout << "���� ������ �� : " << MyTotalValue << " , ���� ������ �� : " << MyPickValue;
			exit(1);
		}
	}
	else { // ����� ��� => ���� ���� ���� ��ȿ�� �˻�
		MyTotalValue = Value;
		MyPickValue = Value - YourTotalValue;
		if (MyPickValue < 1 || MyPickValue > 5) { // ��ȿ�� �˻� 2
			cout << "���� ������ ���� 1�� 5 ������ ���� �ƴմϴ�.";
			cout << "���� ������ �� : " << MyTotalValue << " , ���� ������ �� : " << MyPickValue;
			exit(1);
		}
		if (NumOfGame > 1) { // ���� ó�� ������ ���� ��ȿ�� �˻�� �ش����� ����
			if ((MyPickValue < YourPickValue - 1) || (MyPickValue > YourPickValue + 1)) { // ��ȿ�� �˻� 3
				if (MyChance == 1) { // ������ ���� �� ��ȿ���� ������Ƿ� ������ ����� ������ ������
					if (output)cout << " << ���� Chance�� ����Ͽ����ϴ�. >>" << endl;
					MyChance = -1; // ������ ����ߴٴ� ǥ��
				}
				else { // ������ ���� ��
					cout << "���� ������ ���� ��밡 ������ ���� -1, +0, +1�� �� ���� �ƴմϴ�.";
					cout << "���� ������ ��   : " << MyTotalValue << " (( ���� ������ �� : " << MyPickValue << " ))" << endl;
					cout << "��밡 ������ �� : " << YourTotalValue << " (( ��밡 ������ �� : " << YourPickValue << " ))" << endl;
					exit(1);
				}
			}
		}
	}
	NumOfGame++; // ��ȿ�� �˻縦 ��ģ ���� ���� ���̹Ƿ� ���� Ƚ���� 1 ������Ŵ

	//cout << "���� �����Դϴ�." << endl;
	if (output)cout << "���� ������ ��   : " << MyTotalValue << " (( ���� ������ �� : " << MyPickValue << " ))" << endl;

	int i = 0;
	while (i < GoalNum) { // ���� ������ ���� ������ �ϴ����� ��� ��ǥ���� ���� Ȯ���Ѵ�.
		if ((YourTotalValue < GoalValue[i]) && (MyTotalValue >= GoalValue[i])) {
			MyGoal += 1;
			MyGoalVal[i] = GoalValue[i];
			if (output)cout << "���� ��ǥ�� " << GoalValue[i] << "�� ȹ���ϼ̽��ϴ�. ( ���� ���� ���� : " << MyGoal << " ��)" << endl << endl; // ���� ���� ���
			if (i == GoalNum - 1) { // ���� ������ ��ǥ���� ȹ���Ѵٸ� ������ ����ȴ�.
				finish = 1;		//���� ���� �ǹ�
				if (output)cout << "���� ������ ��ǥ���� ȹ���Ͽ����ϴ�. ������ �����մϴ�." << endl;
				if (output)cout << "(���� ���� : " << MyGoal << " ��)" << "(����� ���� : " << YourGoal << " ��)" << endl;
				if (MyGoal == YourGoal) { // ���� ������ ���ٸ� ���� ������ ������
					int YourFinGoal = 0; //����� ���� ����
					int MyFinalGoal = 0; // ���� ���� ����

					for (int j = 0; j < 7; j++) {
						YourFinGoal += YourGoalVal[j];
						MyFinalGoal += MyGoalVal[j];
					}
					if (MyFinalGoal < YourFinGoal) { // ����� ���� ������ ���� �� ��밡 �¸�
						if (output)
						{
							cout << "��밡 ���ӿ��� �¸��Ͽ����ϴ�. " << endl;
							cout << "��� �� ��ǥ�� �հ� : " << YourFinGoal << " " << endl;
							cout << "���� �� ��ǥ�� �հ� : " << MyFinalGoal << " " << endl;
						}
						YourVic = 1;
					}
					else if (MyFinalGoal == YourFinGoal) { // ���� ������ ���� �� ���º�
						if (output)
						{
							cout << "���� ����� ���º��Դϴ�. " << endl;
							cout << "��� �� ��ǥ�� �հ� : " << YourFinGoal << " " << endl;
							cout << "���� �� ��ǥ�� �հ� : " << MyFinalGoal << " " << endl;
						}
						MyVic = 0;
						YourVic = 0;
					}
					else { // ���� ���� ������ ���� �� ���� �¸�
						if (output)
						{
							cout << "���� ���ӿ��� �¸��Ͽ����ϴ�. " << endl;
							cout << "��� �� ��ǥ�� �հ� : " << YourFinGoal << " " << endl;
							cout << "���� �� ��ǥ�� �հ� : " << MyFinalGoal << " " << endl;
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
					cout << "���� ��� ����." << endl;
				}
			}
		}
		i++;
	}
}
void Judge::CheckYourTurn(int Value[]) { // ��밡 ���� ���� ���� ��ȿ���˻�, ���� ��� ���� Ȯ��, ���� ���� Ȯ��, ���
	if (MyGoal > YourGoal) {
		if (YourChance != -1)
			YourChance = 1;
	} // ����� ���� ���� Ȯ��; ������ ����� ��� 1; ������ �̹� ���� ��� -1; 
	if (Value[0] != 101) { // ��ȿ�� �˻� 1
		cout << "������ ������ ���۰��� " << Value[0] << " ���� 101 ��/�� �ƴմϴ�.";
		exit(1);
	}
	if (Value[2] != -1) { // ��ȿ�� �˻� 1
		cout << "������ ������ ������ ���� " << Value[2] << " ���� -1 �� �ƴմϴ�.";
		exit(1);
	}
	if (NumOfGame == 0) { // ���� ������ ���� 0�̴� => ��밡 �����ν� ���� ���� ���� ���
		YourTotalValue = Value[1];
		YourPickValue = Value[1];
		if (YourPickValue < 1 || YourPickValue > 5) { // ��ȿ�� �˻� 2
			cout << "��밡 ������ ���� 1�� 5 ������ ���� �ƴմϴ�.";
			exit(1);
		}
	}
	else { // ����� ��� => ��밡 ���� ���� ��ȿ�� �˻�
		YourTotalValue = Value[1];
		YourPickValue = Value[1] - MyTotalValue;
		if (YourPickValue < 1 || YourPickValue > 5) { // ��ȿ�� �˻� 2
			cout << "��밡 ������ ���� 1�� 5 ������ ���� �ƴմϴ�.";
			exit(1);
		}
		if (NumOfGame > 1) { // ���� ó�� ������ ���� ��ȿ�� �˻�� �ش����� ����
			if ((YourPickValue < MyPickValue - 1) || (YourPickValue > MyPickValue + 1)) { // ��ȿ�� �˻� 3
				if (YourChance == 1) { // ������ ���� �� ��ȿ���� ������Ƿ� ������ ����� ������ ������
					if (output)cout << " << ��밡 Chance�� ����Ͽ����ϴ�. >>" << endl;
					YourChance = -1; // ��밡 ������ ����� ǥ��
				}
				else { // ������ ������
					cout << "��밡 ������ ���� ���� ������ ���� -1, +0, +1�� �� ���� �ƴմϴ�." << endl;
					cout << "���� ������ ��   : " << MyTotalValue << " (( ���� ������ �� : " << MyPickValue << " ))" << endl;
					cout << "��밡 ������ �� : " << YourTotalValue << " (( ��밡 ������ �� : " << YourPickValue << " ))" << endl;
					cout << " <<<< �ǰ� >>>> " << endl;
					exit(1);
				}
			}
		}
	}

	NumOfGame++; // ��밡 ���� ������ �������Ƿ� ���� Ƚ�� 1 ���� 

	//cout << "����� �����Դϴ�." << endl;
	if (output)cout << "��밡 ������ �� : " << YourTotalValue << " (( ��밡 ������ �� : " << YourPickValue << " ))" << endl;

	for (int i = 0; i < GoalNum; i++) { // ��밡 ���� ���� ������ �ϴ����� ��� ��ǥ���� ���� Ȯ���Ѵ�.

		if ((MyTotalValue < GoalValue[i]) && (YourTotalValue >= GoalValue[i])) {
			YourGoal += 1;
			YourGoalVal[i] = GoalValue[i];
			if (output)cout << "��밡 ��ǥ�� " << GoalValue[i] << "�� ȹ���ϼ̽��ϴ�. ( ����� ���� ���� : " << YourGoal << " ��)" << endl << endl; // ����� ���� ���

			if (i == GoalNum - 1) { // ���� ������ ��ǥ���� ȹ���Ѵٸ� ������ ����ȴ�.
				finish = 1;
				if (output)cout << "��밡 ������ ��ǥ���� ȹ���Ͽ����ϴ�. ������ ����˴ϴ�." << endl;
				if (output)cout << "(���� ���� : " << MyGoal << " ��)" << "(����� ���� : " << YourGoal << " ��)" << endl;

				if (MyGoal == YourGoal) { // ������ ���� �� ���� ���� ��

					if (output)cout << "���� ����� ���º��Դϴ�. " << endl;
					int YourFinGoal = 0; //����� ���� ����
					int MyFinalGoal = 0; // ���� ���� ����

					for (int j = 0; j < 7; j++) {
						YourFinGoal += YourGoalVal[j];
						MyFinalGoal += MyGoalVal[j];
					}
					if (MyFinalGoal < YourFinGoal) { // ����� ���� ������ ���� �� ��밡 �¸�
						if (output)
						{
							cout << "��밡 ���ӿ��� �¸��Ͽ����ϴ�. " << endl;
							cout << "��� �� ��ǥ�� �հ� : " << YourFinGoal << " " << endl;
							cout << "���� �� ��ǥ�� �հ� : " << MyFinalGoal << " " << endl;
						}
						YourVic = 1;
					}
					else if (MyFinalGoal == YourFinGoal) { // ���� ������ ���� �� ���º�
						if (output)
						{
							cout << "���� ����� ���º��Դϴ�. " << endl;
							cout << "��� �� ��ǥ�� �հ� : " << YourFinGoal << " " << endl;
							cout << "���� �� ��ǥ�� �հ� : " << MyFinalGoal << " " << endl;
						}
						MyVic = 0;
						YourVic = 0;
					}
					else { // ���� ���� ������ ���� �� ���� �¸�
						if (output)
						{
							cout << "���� ���ӿ��� �¸��Ͽ����ϴ�. " << endl;
							cout << "��� �� ��ǥ�� �հ� : " << YourFinGoal << " " << endl;
							cout << "���� �� ��ǥ�� �հ� : " << MyFinalGoal << " " << endl;
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
					cout << "���� ��� ����." << endl;
				}
			}
		}
	}
}
void Judge::readOutput(bool output_)
{
	output = output_;
}
int Judge::GetMyVic() { // ���� �¸� ���θ� �ҷ���. 1�� ��� ���� �¸�, 2�� ��� ���º�
	return MyVic;
}
int Judge::GetYourVic() { // ����� �¸� ���θ� �ҷ���. 1�� ��� ���� �й�, 2�� ��� ���º�
	return YourVic;
}
bool Judge::GetFinish()
{
	return finish;
}
Judge::~Judge() { // �Ҹ���
	delete[] GoalValue;
	GoalValue = NULL;
}
