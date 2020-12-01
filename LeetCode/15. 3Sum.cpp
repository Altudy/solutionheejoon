class Solution {
public:
    vector<vector<int>> ans{};
    map<int, int> tree; // <value, count>
    set<vector<int>> s;
    int cur;

    vector<vector<int>> threeSum(vector<int>& nums) {

        if (nums.size() < 3) return ans;

        for (int i = 0; i < nums.size(); i++)
            tree[nums[i]]++;

        for (auto it1 = tree.begin(); it1 != tree.end(); it1++)
        {
            for (auto it2 = it1; it2 != tree.end(); it2++)
            {
                cur = -(it1->first + it2->first);
                auto temp = tree.find(cur);

                if (temp != tree.end())
                {
                    if (it1 == it2 && it1->second>=2)
                    {
                        if (it1 == temp) {
                            if (it1->second >= 3) insert(it1->first, it2->first, temp->first);
                        }
                        else
                            insert(it1->first, it2->first, temp->first);
                    }
                    else if (it1 != it2)
                    {
                        if (it1 == temp && it1->second >= 2) insert(it1->first, it2->first, temp->first);
                        else if(it2 == temp && it2->second >=2) insert(it1->first, it2->first, temp->first);
                        else if(it1 != temp && it2 != temp) insert(it1->first, it2->first, temp->first);
                    }
                }
            }
        }
        ans.assign(s.begin(), s.end());
        return ans;
    }
    void insert(int a, int b, int c)
    {
        vector<int> v{ a, b, c };
        sort(v.begin(), v.end());
        s.insert(v);
    }
};

///////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;

        if (nums.size() < 3)
            return triplets;

        sort(nums.begin(), nums.end());
        const int sum = 0;
        const int min = nums.front();
        const int max = nums.back();
        if (min > sum || max < sum) {
            return triplets;
        }

        for (size_t smallest = 0; smallest < nums.size() - 2; ++smallest) {
            if (nums[smallest] > sum) break;
            if (smallest > 0 && nums[smallest] == nums[smallest - 1]) continue;
            if (nums[smallest] + 2 * max < 0) continue;
            if (nums[smallest] + 2 * min > sum) break;

            two_sum(nums, smallest + 1, sum - nums[smallest], triplets, nums[smallest]);
        }
        return triplets;
    }
private:
    void two_sum(vector<int>& nums, size_t start, const int target, vector<vector<int>>& triplets, int prefix) {
        if (start >= nums.size() || nums.size() - start < 2) return;
        size_t l = start;
        size_t r = nums.size() - 1;

        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                triplets.emplace_back(vector<int>({ prefix, nums[l], nums[r] }));
                l += 1;
                r -= 1;

                while (l < r && nums[l] == nums[l - 1]) l ++;
                while (l < r && nums[r] == nums[r + 1]) r --;
            }
            else {
                sum < target ? l += 1 : r -= 1;
            }
        }
    }
};

*/
