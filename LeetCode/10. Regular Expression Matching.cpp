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
