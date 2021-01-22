class Solution {
public:
    vector<string> letterCombinations(string digits) {
        d = digits;
        len = digits.size();
        if(!len) return ans;
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

        int n = d[len - l] - 48;

        for (int i = 0; i < dial[n].size(); i++)
        {
            s.push_back(dial[n][i]);
            addletter(s, l-1);
            s.pop_back();
        }
    }

private:
    string d;
    int len;
    vector<string> ans;
    vector<vector<char>> dial{ {}, {}, {'a','b','c'},
                              {'d','e','f'},
                              {'g','h','i'},
                              {'j','k','l'},
                              {'m','n','o'},
                              {'p','q','r','s'},
                              {'t','u','v'},
                              {'w','x','y','z'}};
};
