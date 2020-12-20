class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> ans{ intervals[0][0],intervals[0][1] };
        vector<vector<int>> anss;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans[1] >= intervals[i][0]){
                ans[1] = max(ans[1], intervals[i][1]);
            }else
            {
                anss.emplace_back(ans);
                ans = intervals[i];
            }            
        }
        anss.emplace_back(ans);
        return anss;
    }
};
////////////////////////////////////////////////////////////////
/*

const int N = 1e4 + 5;
int sum[N];
bool tag[N];

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int max = 0;
        for (const auto& seg : intervals) {
            max = std::max(max, seg.back());
        }
        memset(sum, 0, sizeof(int) * (max + 1));
        memset(tag, 0, sizeof(bool) * (max + 1));

        for (const auto& seg : intervals)
        {
            int l = seg.front(), r = seg.back();
            if (l == r) {
                tag[l] = true;
            }
            else {
                ++sum[l];
                --sum[r];
            }
        }

        for (int i = 1; i <= max; ++i) {
            sum[i] += sum[i - 1];
        }

        vector<vector<int>> res;

        for (int l = 0, r; l <= max; l = r + 1)
        {
            while (l <= max && sum[l] == 0)
            {
                if (tag[l]) res.emplace_back(vector<int>{l, l});
                ++l;
            }
            
            if (l > max) break;
            
            r = l;
            while (r + 1 <= max && sum[r + 1] > 0) ++r;
            
            res.emplace_back(vector<int>{l, r + 1});
            tag[r + 1] = false;
        }
        return res;
    }
};

*/
