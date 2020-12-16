class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy;
        copy.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                copy[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = copy;
    }
};

//////////////////////////////////////////////////
/* best solution

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto len = matrix.size();
        auto center = (len + 1) / 2;
        for (int i = 0; i < center; i++)
        {
            for (int j = 0; j < len / 2; j++)
            {
                // get last
                int tmp = matrix[len - 1 - j][i];
                //replace corners
                matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
                matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
                matrix[j][len - 1 - i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};

*/
