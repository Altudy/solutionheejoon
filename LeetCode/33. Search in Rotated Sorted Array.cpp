class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i]==target) return i;
        return -1;
    }
};

///////////////////////////////////////////////
/* best solution

class Solution {
public:
int helper(vector<int> &n, int t, int left, int right)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (n[mid] == t)
        return mid;

    if (n[left] <= n[mid])
    {
        if (n[mid] >= t && t >= n[left])
            return helper(n, t, left, mid - 1);
        return helper(n, t, mid + 1, right);
    }
    else
    {
        if (n[mid] <= t && t <= n[right])
            return helper(n, t, mid + 1, right);
        return helper(n, t, left, mid - 1);
    }
}
    
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }
};

*/
