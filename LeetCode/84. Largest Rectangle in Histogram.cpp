typedef pair<int, int> pii;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pii> stk;
        stk.push({ 0,0 });
        heights.push_back(0);

        pii top;
        int n(0), ans(0);

        for (auto hh : heights)
        {
            top = stk.top();
            if (top.first < hh)
                stk.push({ hh,1 });
            else if (top.first == hh)
                stk.top().second++;
            else
            {
                n = 0;
                while (!stk.empty() && (top = stk.top()).first > hh)
                {
                    n += top.second;
                    ans = max(ans, top.first * n);
                    stk.pop();
                }
                if (top.first == hh && !stk.empty()) stk.top().second += n + 1;
                else stk.push({ hh,n + 1 });
            }
        }
        return ans;
    }
};
//////////////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
         int ret = 0;
            height.push_back(0);
            vector<int> index;
            
            for(int i = 0; i < height.size(); i++)
            {
                while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();
                    
                    int sidx = index.size() > 0 ? index.back() : -1;
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                }
                index.push_back(i);
            }
            return ret;   
    }
};

/////////////////////////////////////////////////////////////////////////////
// best solution 2

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), cur = 0, result = 0;
        vector<int> left(n, 0), right(n, 0);
        
        for(int i=0; i<n; ++i) {
            cur = i-1;
            while(cur >= 0 && heights[cur] >= heights[i]) cur = left[cur];
            left[i] = cur;
        }
        
        for(int i=n-1; i>=0; --i) {
            cur = i+1;
            while(cur < n && heights[cur] >= heights[i]) cur = right[cur];
            right[i] = cur;
        }
        
        for(int i=0; i<n; ++i)
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        
        
        return result;
    }
};

*/
