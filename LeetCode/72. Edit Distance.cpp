class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp;
        int a = word1.length();
        int b = word2.length();
        dp.assign(a + 1, vector<int>(b + 1, 0));

        for (int i = 1; i <= a; i++) dp[i][0] = i;
        for (int i = 1; i <= b; i++) dp[0][i] = i;

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[a][b];
    }
};
