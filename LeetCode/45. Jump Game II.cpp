class Solution {
public:
    int jump(vector<int>& nums) {
        int ans(0);
        int idx(0);
        int end = nums[0];
        int next = end;

        while (idx < nums.size() - 1)
        {
            for (int i = idx + 1; i <= end; i++)
            {
                if (i == nums.size() - 1) {
                    return ans + 1;
                }
                if (next < i + nums[i]) {
                    next = i + nums[i];
                    idx = i;
                }
            }
            end = next;
            ans++;
        }
        return ans;
    }
};
