class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        ans.push_back(s[0]);
        vector<int> count(s.size() + 1, 0);
        count[1] = 1;
        int idx(0);

        for (int i = 1; i < s.length(); i++)
        {
            if (idx >= 0 && s[i] == ans[idx])
            {
                if (count[idx + 1] == k - 1) {
                    cout << "\t" << ans;
                    ans.erase(idx - k + 2, k - 1);
                    idx = idx - k + 1;
                    cout << "\t" << ans << endl;
                }
                else {
                    count[idx + 2] = count[idx + 1] + 1;
                    ans.push_back(s[i]);
                    idx++;
                }
            }
            else
            {
                ans.push_back(s[i]);
                count[idx + 2] = 1;
                idx++;
            }
        }
        return ans;
    }
};
////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    string removeDuplicates(string s, int k) {
        auto j = 0;
        stack<int> counts;
        for (auto i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];
            if (j == 0 || s[j] != s[j - 1]) {
                counts.push(1);
            } else if (++counts.top() == k) {
                counts.pop();
                j -= k;
            }
        }
        return s.substr(0, j);
    }
};

*/
