class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx(0);
        int len = nums.size();
        
        for(int cur=0; cur<len; cur++)
        {
            maxidx = max(maxidx, cur+nums[cur]);
            if(maxidx>=len-1) return true;
            if(cur==maxidx) return false;
        }
        return false;
    }
};
////////////////////////////////////////////////
/* best solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int d = 1;
        for (int j=nums.size()-2; j>=0; j--) {
            if (nums[j] < d) d++;
            else d = 1;
        }
        return nums[0] >= d;
    }
};

*/
