class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(auto n : nums)
        {
            sum += n;
            if(ans < sum) ans = sum;
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};
