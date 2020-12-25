class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero(0), one(0), two(0);
        for(auto n : nums)
        {
            if(n==0) zero++;
            else if(n==1) one++;
            else two++;
        }
        int idx(0);
        while(zero--){
            nums[idx]=0; idx++;
        }
        while(one--){
            nums[idx]=1; idx++;
        }
        while(two--){
            nums[idx]=2; idx++;
        }
    }
};
