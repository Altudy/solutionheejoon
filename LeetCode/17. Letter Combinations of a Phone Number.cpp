class Solution {
public:
    vector<string> letterCombinations(string digits) {
        d = digits;
        len = digits.size();
        if (!len) return ans;
        string s;
        addletter(s, len);
        return ans;
    }

    void addletter(string s, int l)
    {
        if (l == 0) {
            ans.emplace_back(s); 
            return;
        }

        int n = d[len - l] - '0';

        for (int i = 0; i < dial[n].size(); i++)
        {
            s += dial[n][i];
            addletter(s, l-1);
            s.pop_back();
        }
    }
