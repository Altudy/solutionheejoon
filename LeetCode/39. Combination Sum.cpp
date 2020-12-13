// best solution
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cndd = candidates;
        vector<int> combination;
        int begin(0);

        backtracking(target, combination, begin);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cndd;

    void backtracking(int target, vector<int>& combination, int begin)
    {
        if (!target) { // target == 0
            ans.emplace_back(combination);
            return;
        }
        for (int i = begin; i < cndd.size() && target >= cndd[i]; i++)
        {
            combination.emplace_back(cndd[i]);
            backtracking(target - cndd[i], combination, i);
            combination.pop_back();
        }
    }
};
