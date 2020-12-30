class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;
        stack.push_back("");

        vector<int> repeat;
        int num;
        bool wasnum = false;

        for (auto c : s)
        {
            // 숫자일 때
            if (c >= 48 && c <= 57)
            {
                if (wasnum) {
                    num = num * 10 + c - 48;
                }
                else {
                    num = c - 48;
                    wasnum = true;
                }
            }

            // 괄호일 때
            else if (c == 91) { // open
                wasnum = false;
                repeat.push_back(num);
                stack.push_back("");
            }
            else if (c == 93) { // close
                num = repeat.back();
                string temp = stack.back();
                stack.pop_back();
                while (num--) stack.back() += temp;
                repeat.pop_back();
            }

            // 문자일 때
            else {
                stack.back() += c;
            }
        }
        return stack[0];
    }
};
//////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    string decode(string& s, int& i){
        string ret = "";
        while(i < s.size() && s[i] != ']'){
            if(!isdigit(s[i])){
                ret += s[i];
                ++i;
            }
            else{
                int n = 0;
                while(isdigit(s[i])){
                    n = n * 10 + s[i] - '0';
                    ++i;
                }
                ++i;
                string t = decode(s, i);
                ++i;
                cout << t << " : " << n << endl;
                while(n > 0){ 
                    ret += t;
                    --n;
                }
            }
        }
        return ret;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};

*/
