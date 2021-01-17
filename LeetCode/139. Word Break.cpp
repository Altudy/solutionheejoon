class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len+1, 0);
        dp[0] = true;
        
        unordered_set<string> dict;
        for(auto word : wordDict)
            dict.insert(word);
        
        for(int i=1; i<=len; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(dp[j])
                {
                    string candi = s.substr(j, i-j);
                    if(dict.find(candi) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
};
//////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        unordered_set<string> dict;
        for(auto word : wordDict)
            dict.insert(word);
        
        for(int i =0; i <= n; i++){
            for(auto word : wordDict){
                int j = word.length();
                if(i>= j && dp[i-j] && word == s.substr(i-j, j)){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];                   
    }
};

*/
