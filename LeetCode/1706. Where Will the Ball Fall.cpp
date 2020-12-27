class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<int> ans(COL, -1);

        for (int i = 0; i < COL; i++)
        {
            int row = 0;
            int col = i;
            while (1)
            {
                if (row >= ROW) {
                    ans[i] = col; break;
                }

                if (grid[row][col] == 1) { 
                    if (col >= COL - 1) break;
                    else if (grid[row][col + 1] == -1) break;
                    else {
                        row++; col++;
                    }
                }
                else {
                    if (col <= 0) break;
                    if (grid[row][col - 1] == 1) break;
                    else {
                        row++; col--;
                    }
                }
            }
        }
        return ans;
    }
};
