#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long ll;

ll do_sub(vector<ll>& numbers, vector<char>& operation, int add, int mul);
ll do_mul(vector<ll>& numbers, vector<char>& operation, int add, int sub);

void check(string& expression, vector<ll>& num, vector<char>& op, bool& add, bool& sub, bool& mul)
{
	int n(0);
	for (auto s : expression)
	{
		if (isdigit(s)) {
			n = n * 10 + s - '0';
		}
		else {
			num.emplace_back(n);
			op.emplace_back(s);
			n = 0;
			if (s == '+') add = true;
			else if (s == '-') sub = true;
			else if (s == '*') mul = true;
		}
	}
	num.emplace_back(n);
}

ll do_add(vector<ll>& numbers, vector<char>& operation, int sub, int mul)
{
	vector<ll> num = numbers;
	vector<char> op = operation;
	int idx(0);

	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '+')
		{
			idx = i;
			while (num[idx] == INT_MAX) idx--;
			num[idx] += num[i + 1];
			num[i + 1] = INT_MAX;
		}
	}

	if (sub > 0 || mul > 0) {
		if (sub > mul) return do_sub(num, op, -1, mul);
		else if (sub < mul) return do_mul(num, op, -1, sub);
	}

	return num.front();
}

ll do_sub(vector<ll>& numbers, vector<char>& operation, int add, int mul)
{
	vector<ll> num = numbers;
	vector<char> op = operation;
	int idx(0);

	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '-')
		{
			idx = i;
			while (num[idx] == INT_MAX) idx--;
			num[idx] -= num[i + 1];
			num[i + 1] = INT_MAX;
		}
	}
	
	if (add > 0 || mul > 0) {
		if (add > mul) return do_add(num, op, -1, mul);
		else if (add < mul) return do_mul(num, op, add, -1);
	}

	return num.front();
}

ll do_mul(vector<ll>& numbers, vector<char>& operation, int add, int sub)
{
	vector<ll> num = numbers;
	vector<char> op = operation;
	int idx(0);

	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '*')
		{
			idx = i;
			while (num[idx] == INT_MAX) idx--;
			num[idx] *= num[i + 1];
			num[i + 1] = INT_MAX;
		}
	}

	if (add > 0 || sub > 0) {
		if (add > sub) return do_add(num, op, sub, -1);
		else if (add < sub) return do_sub(num, op, add, -1);
	}

	return num.front();
}

long long solution(string expression) {
	long long answer = 0;
	vector<ll> num;
	vector<char> op;
	bool add = false;
	bool sub = false;
	bool mul = false;

	check(expression, num, op, add, sub, mul);

	if (add && sub && mul) {
		answer = max(answer, abs(do_add(num, op, 1, 2)));
		answer = max(answer, abs(do_add(num, op, 2, 1)));
		answer = max(answer, abs(do_sub(num, op, 1, 2)));
		answer = max(answer, abs(do_sub(num, op, 2, 1)));
		answer = max(answer, abs(do_mul(num, op, 1, 2)));
		answer = max(answer, abs(do_mul(num, op, 2, 1)));
	}
	else if (add && sub) {
		answer = max(answer, abs(do_add(num, op, 1, -1)));
		answer = max(answer, abs(do_sub(num, op, 1, -1)));
	}
	else if (add && mul) {
		answer = max(answer, abs(do_add(num, op, -1, 1)));
		answer = max(answer, abs(do_mul(num, op, 1, -1)));
	}
	else if (sub && mul) {
		answer = max(answer, abs(do_sub(num, op, 2, 1)));
		answer = max(answer, abs(do_mul(num, op, 1, 2)));
	}
	else if (add) {
		answer = max(answer, abs(do_add(num, op, -1, -1)));
	}
	else if (sub) {
		answer = max(answer, abs(do_sub(num, op, -1, -1)));
	}
	else if (mul) {
		answer = max(answer, abs(do_mul(num, op, -1, -1)));
	}

	return answer;
}
