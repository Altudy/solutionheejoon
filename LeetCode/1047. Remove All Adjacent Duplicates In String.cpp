class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        int idx(0);
        ans.push_back(S[0]);

        for (int i = 1; i < S.length(); i++)
        {
            if (S[i] == ans[idx]) {
                ans.pop_back();
                idx--;
            }
            else {
                ans.push_back(S[i]);
                idx++;
            }
        }
        return ans;
    }
};
////////////////////////////////////////////
/* best solution

class Solution {
public:
    string removeDuplicates(string S) {
        const int n=S.size();
        string ans="";
        
        for(int i=0;i<n;i++) {
            if (!ans.empty() && S[i]==ans.back()) {
                ans.pop_back();
            } else {
                ans.push_back(S[i]);
            }
        }
        return ans;
    }
};

*/
