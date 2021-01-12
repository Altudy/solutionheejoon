class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        
        if(s[len-1]=='0') dp[len-1] = 0;
        else dp[len - 1] = 1;

        if(len > 1){
            if((s[len-2]=='1') || (s[len-2]=='2' && s[len-1]<='6')) dp[len-2] = dp[len-1]+1;
            else if(s[len-2]!='0') dp[len-2] = dp[len-1];
        }
        
        for(int i=len-3; i>=0; i--)
        {
            if(s[i]=='0') continue;
            
            if((s[i]=='1') || (s[i]=='2' && s[i+1]<='6')) dp[i] = dp[i+1] + dp[i+2];
            else dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
////////////////////////////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int prev = 1, prev2 = 1, curr = 1;
        
        int n = s.length();
        if(s[0] == '0')
            return 0;
        
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                if(!(s[i-1] == '1' || s[i-1] == '2'))
                    return 0;
                curr = prev2;
            }
            else if(s[i-1] != '0' && ((s[i-1] == '1') || (s[i] <= '6' && s[i-1] == '2')))
                curr = prev + prev2;
            else
                curr = prev;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};

*/
