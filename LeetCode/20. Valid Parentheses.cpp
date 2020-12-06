class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.emplace(s[0]);
        char top;
        for (int i=1; i<s.size(); i++)
        {
            if (stk.size()) {
                top = stk.top();
                if (s[i] == ')' && top == '(') stk.pop();
                else if (s[i] == '}' && top == '{') stk.pop();
                else if (s[i] == ']' && top == '[') stk.pop();
                else stk.emplace(s[i]);
            }
            else stk.emplace(s[i]);
        }
        if (stk.empty()) return true;
        else return false;
    }
};

/////////////////////////////////////////
/* best solution

class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '(':
                    p.push(')');
                    break;
                case '{':
                    p.push('}');
                    break;
                case '[':
                    p.push(']');
                    break;
                default:
                    if(!p.empty() && p.top() == s[i])
                        p.pop();
                    else
                        return false;
                    break;
            }
        }
        return p.empty();
    }
};

*/
