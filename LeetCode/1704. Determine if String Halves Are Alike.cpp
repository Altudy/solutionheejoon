class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.length() / 2);
        string b = s.substr(s.length() / 2, s.length() - 1);
        return count(a) == count(b);
    }
    int count(string s)
    {
        int ans(0);
        for (auto letter : s)
        {
            if (letter == 'a') ans++;
            else if (letter == 'e') ans++;
            else if (letter == 'i') ans++;
            else if (letter == 'o') ans++;
            else if (letter == 'u') ans++;
            else if (letter == 'A') ans++;
            else if (letter == 'E') ans++;
            else if (letter == 'I') ans++;
            else if (letter == 'O') ans++;
            else if (letter == 'U') ans++;
        }
        return ans;
    }
};
