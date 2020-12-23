typedef pair<int, int> pii;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans(0);
        priority_queue<pii> pq;
        pii high;

        for (int i = 0; i < height.size(); i++)
            pq.push(make_pair(height[i], i));

        if(!pq.empty()) high = pq.top();

        int maxidx = high.second;
        int minidx = high.second;
        int premax = high.second;
        int premin = high.second;

        while (!pq.empty())
        {
            premax = maxidx;
            premin = minidx;

            while (!pq.empty())
            {
                high = pq.top(); pq.pop();
                maxidx = max(maxidx, high.second);
                minidx = min(minidx, high.second);
                if (!pq.empty() && high.first != pq.top().first) break;
            }


            int h = high.first;
            if (h < 1) break;

            for (int i = minidx + 1; i < premin; i++)
            {                
                if (h - height[i] > 0) ans += h - height[i];
            }
            for (int i = premax + 1; i < maxidx; i++)
            {
                if (h - height[i] > 0) ans += h - height[i];
            }
        }
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> maxRight(size);
        int total = 0;
        
        int maxH = 0;
        for (int i = size-1; i >=0 ; i--) {
            maxH = max(maxH, height[i]);
            maxRight[i] = maxH;
        }
        
        maxH = 0;
        for (int i = 0; i < size; i++) {
            maxH = max(maxH, height[i]);
            total += (min(maxH, maxRight[i]) - height[i]);
        }
        return total;
    }
};

*/
