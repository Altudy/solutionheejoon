class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) sum += n;

        if (sum % 2 == 1) return false;
        sum /= 2;

        int len = nums.size();
        vector<vector<bool>> dp(len + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= len; i++)
        {
            int num = nums[i - 1];
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j-num >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - num];
            }
            if (dp[i][sum]) return true;
        }
        return dp[len][sum];
    }
};
/////////////////////////////////////////////////////////////////////
// best solution 1

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if ((sum & 1) == 1) return false;
        sum /= 2;

        int n = nums.size();
        vector<bool> dp(sum+1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = sum; i > 0; i--) {
                if (i >= num)
                    dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[sum];
    }
};

/////////////////////////////////////////////////////////////////////
// best solution 2

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<100 * 200 / 2 + 1> bits(1);
        int sum = 0;
        for (const int &num : nums) {
            sum += num;
            bits |= bits << num;
        }
        return !(sum & 1) && bits[sum >> 1];
    }
};
