class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        vector<int> per;
        per.reserve(6);
        backtracking(nums, per);
        return ans;
    }
private:
    int len;
    vector<vector<int>> ans;

    void backtracking(vector<int>& nums, vector<int> per)
    {
        if (per.size() == len) {
            ans.emplace_back(per); return;
        }
        for (int i = 0; i < len; i++)
        {
            per.emplace_back(nums[i]);
            if (promising(nums, per)) backtracking(nums, per);
            per.pop_back();
        }
    }

    bool promising(vector<int>& nums, vector<int> per)
    {
        int k = per.size();
        for (int i = 0; i < k - 1; i++)
        {
            if (per[i] == per[k - 1]) return false;
        }
        return true;
    }
};
/////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:    
    inline bool checkExist(vector<int> &temp, const int value){
        for(int i = 0; i < temp.size(); i++)
            if(value == temp.at(i)) 
                return true;
        return false;
    }
    
    void permutation(vector<vector<int>> &result, vector<int> &temp, const vector<int> &nums){
        if(temp.size() == nums.size()){
            result.push_back(temp);
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                if(checkExist(temp, nums.at(i))) continue;  
                else{
                    temp.push_back(nums.at(i));
                    permutation(result, temp, nums);
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        temp.reserve(nums.size());
        
        permutation(result, temp, nums);
        
        return result;
    }
};

*/
