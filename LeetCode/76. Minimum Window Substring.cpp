class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        string ans = "";

        for (auto c : t) m[c]++;
        int ms = m.size();

        int n(0), idx1(0), idx2(0);
        int slen = s.length();

        while (idx2 < slen)
        {
            if (m.find(s[idx2]) == m.end()) {
                idx2++; continue;
            }
            if (!(--m[s[idx2]])) n++;

            while (n == ms && idx1 < slen)
            {
                if (m.find(s[idx1]) == m.end()) {
                    idx1++; continue;
                }

                if (!(m[s[idx1]]++)) {
                    n--;
                    if (!ans.length() || idx2 - idx1 + 1 < ans.length())
                        ans = s.substr(idx1, idx2 - idx1 + 1);
                }
                idx1++;
            }
            idx2++;
        }
        return ans;
    }
};
/////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length();
        int nt = t.length();

        vector<int> freq(128, 0);
        for (int i = 0; i < nt; i++)
            freq[t[i]]++;

        int requirement = nt;
        int si = 0, ei = 0;
        int len = (int)1e8;
        int head = 0;

        while (ei < ns) {
            if (freq[s[ei++]]-- > 0) requirement--;

            while (requirement == 0) {
                if (ei - si < len)
                    len = (ei - (head = si));

                if (freq[s[si++]]++ == 0)
                    requirement++;
            }
        }
        return len == (int)1e8 ? "" : s.substr(head, len);
    }
};

*/
