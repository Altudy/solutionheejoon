class Solution {
public:
    int ROW;
    int COL;

    bool find(vector<vector<char>>& board, string& word, int idx, int r, int c)
    {
        if (idx == word.size()) return true;
        if (r < 0 || r >= ROW || c < 0 || c >= COL) return false;
        if (board[r][c] != word[idx]) return false;

        char temp = board[r][c];
        board[r][c] = ' ';

        if (find(board, word, idx + 1, r - 1, c) ||
            find(board, word, idx + 1, r, c + 1) ||
            find(board, word, idx + 1, r + 1, c) ||
            find(board, word, idx + 1, r, c - 1)) return true;

        board[r][c] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();

        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                if (board[i][j] == word[0] && find(board, word, 0, i, j))
                    return true;
        return false;
    }
};
