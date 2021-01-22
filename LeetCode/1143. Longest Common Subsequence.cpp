class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        
        vector<vector<int>> dp;
        dp.assign(len1+1, vector<int>(len2+1, 0));
        
        for(int i=0; i<len1; i++)
        {
            for(int j=0; j<len2; j++)
            {
                if(text1[i]==text2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[len1][len2];
    }
};
//////////////////////////////////////////////////////////////////
// best solution 1

class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        if (a.size() < b.size()) return longestCommonSubsequence(b, a);

        vector<vector<short>> m(2, vector<short>(b.size() + 1));

        for (auto i = 1; i <= a.size(); ++i)
            for (auto j = 1; j <= b.size(); ++j)
                if (a[i - 1] == b[j - 1]) m[i % 2][j] = m[(i -1) % 2][j - 1] + 1;
                else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);

        return m[a.size() % 2][b.size()];
    }
};
