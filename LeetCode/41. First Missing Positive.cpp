class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> chk;
        chk.assign(302, false);
        int ans;
        
        for(auto n : nums)
            if(n>0 && n<302) chk[n] = true;

        for(int i=1; i<302; i++)
        {
            if(chk[i]==false) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
///////////////////////////////////////////////
/* best solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int a=1;
        sort(nums.begin(), nums.end());
        for (int i:nums){
            if (i==a){
                a = i+1;
            }
        }
        return a;
    }
};

*/
