// backtracking
class Solution {
public:
    void backtracking(vector<int>& nums, int idx, vector<vector<int>>& subs, vector<int>& sub)
    {
        subs.push_back(sub);
        for(int i=idx; i<nums.size(); i++){
            sub.push_back(nums[i]);
            backtracking(nums, i+1, subs, sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        backtracking(nums, 0, subs, sub);
        return subs;
    }
};

/////////////////////////////////////////////////////
// iterative

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
}; 

////////////////////////////////////////////////////
// bit manipulation

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        
        for(int i=0; i<p; i++)
            for(int j=0; j<n; j++)
                if((i>>j) & 1)
                    subs[i].push_back(nums[j]);
        return subs;
    }
};
