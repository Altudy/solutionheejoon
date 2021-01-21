class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        vector<int> minsub = { nums[0] };
        vector<int> maxsub = { nums[0] };

        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            int num = nums[i];
            minsub.emplace_back(min(num, min(minsub[i - 1] * num, maxsub[i - 1] * num)));
            maxsub.emplace_back(max(num, max(minsub[i - 1] * num, maxsub[i - 1] * num)));
            ans = max(ans, maxsub.back());
        }
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////
// best solution 1

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr=nums[0], max_temp=nums[0], min_temp=nums[0], result=nums[0]; 
        for(int i=1; i<nums.size(); i++)
        {
            curr = nums[i]; 
            int temp = max(max_temp*curr, max(curr, min_temp*curr)); 
            min_temp = min(min_temp*curr,min(curr, max_temp*curr)); 
            max_temp = temp;
            result = max(max_temp,result);  
        }
        return result;
    }
};
////////////////////////////////////////////////////////////////////////////////////////
// best solution 2

int maxProduct(int A[], int n) {
    int r = A[0];

    for (int i = 1, imax = r, imin = r; i < n; i++) {
        if (A[i] < 0)
            swap(imax, imin);

        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);
        r = max(r, imax);
    }
    return r;
}
