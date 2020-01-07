#include <string>       //프로그래머스 문자열 압축
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int unit(1), idx(0), cut(0), num(0), temp(0), ans = answer;
    int t(0);   //얼마나 연속으로 잘리는지

    for (unit = 1; unit <= s.length() / 2; unit++)
    {   
        for (idx = 0; idx <= s.length() - unit; idx+=unit)
        {
            temp = cut;
            for (int i = idx; i < idx + unit; i++)
            {
                if (s[i] != s[i + unit]) {
                    t = 0; break;
                }
                if (i == idx + unit - 1) {
                    cut+=unit; t++;
                }
            }
            if(t==1 && cut > temp) num++;
            if (t == 999) num++;
            else if (t == 99) num++;
            else if (t == 9) num++;
        }
        answer = min(answer, ans - cut + num);
        cout << "unit : " << unit;
        cout << " cut : " << cut;
        cout << " num : " << num;
        cout << " ans : " << answer <<endl;
        cut = 0;
        num = 0;
    }
    cout << answer << endl;
    return answer;
}