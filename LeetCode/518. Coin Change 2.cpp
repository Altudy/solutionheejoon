class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp;
        int len = coins.size();
        dp.assign(len + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= len; i++) dp[i][0] = 1;

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[len][amount];
    }
};
///////////////////////////////////////////////////////////////////////////
// best solution 1

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5001]={0};
        dp[0]=1;
        for(auto i: coins)
            for(int j=i;j<=amount;j++)
                dp[j]+=dp[j-i];
        return dp[amount];
    }
};
