class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        vector<int> pal(length, 0);

        int maxlen = 1;
        int maxidx = 0;
        bool even = false;

        for (int i = 0; i < length - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                pal[i]++;
                if (pal[i]*2 > maxlen) {
                    maxlen = pal[i]*2; maxidx = i; even = true;
                }
                for (int j = 1; j <= length/2; j++)
                {
                    if (i - j < 0 || i + 1 + j >= length) break;
                    if (s[i - j] == s[i + 1 + j]) {
                        pal[i]++;
                        if (pal[i]*2 > maxlen) {
                            maxlen = pal[i]*2; maxidx = i;
                        }
                    }
                    else break;
                }
            }
        }

        pal.assign(length, 1);

        for (int i = 1; i < length; i++)
        {
            for (int j = 1; j <= length/2; j++)
            {
                if (i - j < 0 || i + j >= length) break;
                if (s[i - j] == s[i + j]) {
                    pal[i]++;
                    if (pal[i]*2-1 > maxlen) {
                        maxlen = pal[i]*2-1; maxidx = i;
                        even = false;
                    }
                }
                else break;
            }
        }

        cout << "idx : " << maxidx << " len : " << maxlen << endl;

        string ans;

        if (even)
            ans = s.substr(maxidx - maxlen/2 + 1, maxlen);
        else
            ans = s.substr(maxidx - maxlen/2, maxlen);

        return ans;      
    }
};



////////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len<=1)return s;
        
        int ansLen=0;
        int ansIdx=0;
        int i=0;
        while(i<len){
            int l=i, r=i;
            while(r+1<len && s[r]==s[r+1])r++;
            //[l, r]
            i=r+1;
            while( 0<=l-1 && r+1<len && s[l-1]==s[r+1] ){
                l--; r++;
            }
            //[l,r]
            if( r-l+1 > ansLen ){
                ansLen = r-l+1;
                ansIdx = l;
            }
            
        }
        return s.substr(ansIdx, ansLen);
    }
};

*/
