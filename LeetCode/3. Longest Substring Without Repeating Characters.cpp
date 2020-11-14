class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx1(0), idx2(1), len(1), ans(1);
        int L = s.length();
        if(L==0) return 0;

        unordered_map<char, bool> m;
        m[s[idx1]] = true;
        
        while(idx2<L)
        {
            if(idx1==idx2){
                idx2++;
                m[s[idx1]] = true;
                len = 1;
                continue;
            }
            
            if(m[s[idx2]]==true){
                m[s[idx1]] = false;
                idx1++;
                len--;
            }
            else{
                m[s[idx2]] = true;
                idx2++;
                len++;
            }
            
            if(len>ans) ans = len;
        } 
        return ans;
    }
};

/* Best Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> loc(256, -1);
        int start=0;
        int maxl=0;
        for(int i=0; i<s.size(); ++i) {
            const auto& c = s[i];
            if(loc[c]>=start) {
                maxl=max(maxl, i-start);
                start=loc[c]+1;
            }
            loc[c]=i;
        }
        maxl=max(maxl,static_cast<int>(s.size())-start);
        return maxl;
    }
};
*/
