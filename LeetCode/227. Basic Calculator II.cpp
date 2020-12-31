class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num(0), ans(0);
        int sign(0); // 0:+ 1:- 2:* 3:/

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ') continue;
            else if (s[i] == '+') sign = 0;
            else if (s[i] == '-') sign = 1;
            else if (s[i] == '*') sign = 2;
            else if (s[i] == '/') sign = 3;
            else
            {
                num = findnum(s, i);
                if (sign == 0) stk.push(num);
                else if (sign == 1) stk.push(-num);
                else if (sign == 2) stk.top() *= num;
                else if (sign == 3) stk.top() /= num;
            }
        }
        while (!stk.empty())
        {
            ans += stk.top(); stk.pop();
        }
        return ans;
    }
private:
    int findnum(string& s, int& i)
    {
        int num(0);
        while (isdigit(s[i]))
        {
            num = num*10 - '0' + s[i];
            i++;
        }
        i--;
        return num;
    }
};
///////////////////////////////////////////////////
/*

class Solution {
public:
    int calculate(string s) {
        int currentNumber = 0;
        int lastNumber = 0;
        int result = 0;
        char sign = '+';
        char currentChar;

        for (int ii = 0; ii < s.length(); ++ii) {
            currentChar = s[ii];

            if (isdigit(currentChar)) {
                currentNumber = currentNumber * 10 + (currentChar - '0');
            }

            if ((!isdigit(currentChar) && (currentChar != ' ')) || ii == s.length() - 1) {
                if (sign == '+') {
                    result += lastNumber;
                    lastNumber = currentNumber;
                }
                else if (sign == '-') {
                    result += lastNumber;
                    lastNumber = -currentNumber;
                }
                else if (sign == '*') {
                    lastNumber = (lastNumber * currentNumber);
                }
                else if (sign == '/') {
                    lastNumber = (lastNumber / currentNumber);
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }

        result += lastNumber;
        return result;
    }
};

*/
