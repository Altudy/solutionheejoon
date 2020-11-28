class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size() - 1;
        int ans(0), temp(0);

        while (s<e)
        {
            ans = max(ans, (e - s) * min(height[s], height[e]));
            cout << "s : " << s << " e : " << e << " ans : " << ans << endl;
            if (height[s] >= height[e])
            {
                temp = e - 1;
                while (height[temp] < height[e] && temp > s) temp--;
                e = temp;
            }
            else
            {
                temp = s + 1;
                while (height[temp] < height[s] && temp < e) temp++;
                s = temp;
            }
        }

        return ans;
    }
};

/////////////////////////////////////////////
/* best solution

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size() - 1;
        int ans(0);

        while (s!=e)
        {
            ans = max(ans, (e - s) * min(height[s], height[e]));

            if(height[s]>height[e]) e--;
            else s++;
        }
        return ans;
    }
};

*/
