class Solution {
public:
    bool isMatch(string s, string p) {

        vector<int> type;
        type.assign(31, 0);
        // 0 : nothing / 1 : "." / 2 : "*" / 3 : ".*"

        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == '.') type[i] = 1;
            else if (p[i] == '*') {
                if (p[i - 1] != '.') type[i - 1] = 2;
                else  type[i - 1] = 3;
            }
        }

        int sp(0), pp(0);
        return backtracking(s, p, type, sp, pp);
    }

private:
    bool backtracking(string& s, string& p, vector<int>& type, int sp, int pp)
    {
        if (sp == s.length() && pp == p.length()) return true;

        switch (type[pp])
        {
        case 1: // '.'
            if (sp >= s.length() || pp >= p.length()) return false;
            return backtracking(s, p, type, sp + 1, pp + 1);
            break;
        case 2: // '*'
            for (int i = sp; i <= s.length(); i++)
            {
                if (backtracking(s, p, type, i, pp + 2)) return true;
                if (sp >= s.length() || pp >= p.length()) return false;
                if (s[i] != p[pp]) break;
            }
            break;
        case 3: // '.*'
            for (int i = sp; i <= s.length(); i++)
            {
                if (backtracking(s, p, type, i, pp + 2)) return true;
                if (sp >= s.length() || pp >= p.length()) return false;
            }
            break;
        default: // nothing
            if (sp >= s.length() || pp >= p.length()) return false;
            if (s[sp] == p[pp]) return backtracking(s, p, type, sp + 1, pp + 1);
            else return false;
            break;
        }
        return false;
    }
};
///////////////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    bool isMatch(string s, string p) {
        bool OPT[s.length() + 1][p.length() + 1];
        for(int i = 0; i < s.length() + 1; i++){
            for(int j = 0; j < p.length() + 1; j++)
                OPT[i][j] = false;
        }
        OPT[0][0] = true;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == '*' && OPT[0][i - 1]) {
                OPT[0][i+1] = true;
            }
        }
        for (int i = 0 ; i < s.length(); i++) {
            for (int j = 0; j < p.length(); j++) {
                if (p[j] == '.')
                    OPT[i+1][j+1] = OPT[i][j];
                if (p[j] == s[i]) 
                    OPT[i+1][j+1] = OPT[i][j];
                if (p[j] == '*') {
                    if (p[j-1] != s[i] && p[j-1] != '.')
                        OPT[i+1][j+1] = OPT[i+1][j-1];
                    else
                        OPT[i+1][j+1] = (OPT[i+1][j] || OPT[i][j+1] || OPT[i+1][j-1]);
                }
            }
        }
        return OPT[s.length()][p.length()];
    }
};

*/
