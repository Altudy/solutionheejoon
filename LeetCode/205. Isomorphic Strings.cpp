class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hashmap1;
        map<char, char> hashmap2;
        
        for(int i=0; i<s.length(); i++)
        {
            if(hashmap1.find(s[i]) == hashmap1.end())
                hashmap1[s[i]] = t[i];
            else if(hashmap1[s[i]] != t[i]) return false;

            if(hashmap2.find(t[i]) == hashmap2.end())
                hashmap2[t[i]] = s[i];
            else if(hashmap2[t[i]] != s[i]) return false;
        }
        return true;
    }
};

////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> map1(256, 0);
        vector<char> map2(256, 0);
        for (int i = 0, n = s.size(); i < n; i++) {
            if ((map1[s[i]] && map1[s[i]] != t[i]) || 
                (map2[t[i]] && map2[t[i]] != s[i])) {
                return false;
            }
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return true;
    }
};

auto speedUp = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

*/
