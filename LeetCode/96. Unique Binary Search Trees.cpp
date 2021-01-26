class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(20, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++)
        {
            for(int k=0; k<i; k++)
            {
                dp[i] += dp[k] * dp[i-k-1];
            }
        }
        return dp[n];
    }
};
