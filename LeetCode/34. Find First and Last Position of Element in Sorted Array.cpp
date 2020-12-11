class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        binarysearch(nums, target, 0, nums.size() - 1);
        if (ans[1] == -1) ans[0] = -1;
        return ans;
    }
private:
    vector<int> ans = { 100000, -1 };

    void binarysearch(vector<int>& n, int t, int s, int e)
    {
        if (s > e) return;

        int m = (s + e) / 2;

        if (n[m] == t) {
            ans[0] = min(ans[0], m);
            ans[1] = max(ans[1], m);
            binarysearch(n, t, s, m - 1);
            binarysearch(n, t, m + 1, e);
        }
        else if (n[m] < t) {
            binarysearch(n, t, m + 1, e);
        }
        else {
            binarysearch(n, t, s, m - 1);
        }
    }
};

////////////////////////////////////////////////////////////
/* best solution 1

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v(2);
        v[0]=-1;
        v[1]=-1;
        if(nums.size()==0)return v;
        int n=nums.size();
        if(target>nums[n-1]||target<nums[0])
            return v;
        int lower=(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        int upper=(upper_bound(nums.begin(),nums.end(),target)-nums.begin());
        if(lower==upper&&nums[lower]!=target)
            return v;
        else if(lower==upper&&nums[lower]==target)
        {
            v[0]=lower;
            v[1]=lower;
        }
        else
        {
            v[0]=lower;
            v[1]=upper-1;
        }
        return v;
    }
};

*/
/* best solution 2

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end() && *it == target) {
            int first = it - nums.begin();
            it = upper_bound(nums.begin(), nums.end(), target);
            it--;
            return {first, (int)(it - nums.begin())};
        }
        return {-1, -1};
    }
};

*/
