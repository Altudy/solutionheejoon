#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string p) {
    if (p.empty()) return "";

    stack<char> stk;
    int idx(0), sum(0);

    for (;; idx++)
    {
        if (p[idx] == '(') {
            sum++;
            stk.push(p[idx]);
        }
        else {
            sum--;
            if (!stk.empty() && stk.top() == '(') stk.pop();
            else stk.push(p[idx]);
        }
        if (sum == 0) break;
    }

    string u = p.substr(0, idx + 1);
    string v = p.substr(idx + 1);

    if (stk.empty())
        return u + solution(v);
    else
    {
        string s;
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') s.push_back(')');
            else s.push_back('(');
        }
        return '(' + solution(v) + ')' + s;
    }
    return p;
}
