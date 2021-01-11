class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 2e9);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] < 0) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if (dp[amount] == 2e9) return -1;
        return dp[amount];
    }
};
