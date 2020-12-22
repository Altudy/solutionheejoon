class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> map;
        map.assign(row, vector<int>(col));
        map[0][0] = grid[0][0];
        
        for(int i=1; i<row; i++)
            map[i][0] = grid[i][0] + map[i-1][0];
        for(int i=1; i<col; i++)
            map[0][i] = grid[0][i] + map[0][i-1];
        
        for(int i=1; i<row; i++)
        {
            for(int j=1; j<col; j++)
            {
                map[i][j] = min(map[i-1][j] + grid[i][j], map[i][j-1] + grid[i][j]);
            }
        }
        return map[row-1][col-1];
    }
};
