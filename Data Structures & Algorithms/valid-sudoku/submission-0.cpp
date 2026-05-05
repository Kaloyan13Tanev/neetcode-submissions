class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<vector<unordered_set<char>>> squares(3, vector<unordered_set<char>>(3));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (rows[i].find(board[i][j]) != rows[i].end() || cols[j].find(board[i][j]) != cols[j].end() 
                    || squares[i / 3][j / 3].find(board[i][j]) != squares[i / 3][j / 3].end())
                    {
                        return false;
                    }

                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    squares[i / 3][j / 3].insert(board[i][j]);
                }
                
            }
        }

        return true;
    }
};
