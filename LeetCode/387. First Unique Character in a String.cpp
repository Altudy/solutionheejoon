class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        int ans(-1);
        
        for(auto c : s)
        {
            if(hashmap.find(c) == hashmap.end())
                hashmap[c] = 1;
            else {
                hashmap[c]++;
            }
        }
        
        for(int i=0; i<s.length(); i++)
        {
            if(hashmap[s[i]] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
//////////////////////////////////////////////
/*

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alpha(26, 0);
        
        for(auto c : s)
            alpha[c - 'a']++;
        for(int i=0; i<s.length(); i++)
            if(alpha[s[i] - 'a'] == 1) return i;
        
        return -1;
    }
};

*/
