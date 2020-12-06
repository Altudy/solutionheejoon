class Solution {
 public:
     vector<string> generateParenthesis(int n) {
         back(n, n, n, "");
         return ans;
     }

 private:
     vector<string> ans;
     void back(int n, int left, int right, string s)
     {
         if (right < left || left < 0) return;
         if (right == 0) {
             ans.emplace_back(s);
             return;
         }

         back(n, left - 1, right, s + "(");
         back(n, left, right - 1, s + ")");
     }
 };
