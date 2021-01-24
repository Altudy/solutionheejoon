// best solution 1

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int ROW = matrix.size();
        int COL = matrix[0].size();
        int ans = 0;
        vector<int> height(COL, 0);
        vector<int> left(COL, 0);
        vector<int> right(COL, COL);

        for(int i=0; i<ROW; i++)
        {
            int cur_left = 0;
            int cur_right = COL;

            for(int j=0; j<COL; j++) {
                if(matrix[i][j]=='1') height[j]++;
                else height[j] = 0;
            }

            for(int j=0; j<COL; j++) {
                if(matrix[i][j]=='1') left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0; cur_left = j+1;
                }
            }

            for(int j=COL-1; j>=0; j--) {
                if(matrix[i][j]=='1') right[j] = min(right[j], cur_right);
                else {
                    right[j] = COL; cur_right = j;
                }
            }

            for(int j=0; j<COL; j++) {
                ans = max(ans, (right[j]-left[j])*height[j]);
            }
        }
        return ans;        
    }
};
