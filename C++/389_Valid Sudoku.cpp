class Solution {
public:
    /**
     * @param board: the board
     * @return: wether the Sudoku is valid
     */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if (!checkRow(board))
            return false;
        if (!checkCol(board))
            return false;
        return checkSquare(board);
    }

private:
    const int N = 9;

    bool checkRow(const vector<vector<char> > &board) {
        vector<bool> row(N, false);
        for (int i = 0; i < N; i++) {
            fill(row.begin(), row.end(), false);
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.')
                    continue;
                if (row[board[i][j] - '1'])
                    return false;
                row[board[i][j] - '1'] = true;
            }
        }
        return true;
    }

    bool checkCol(const vector<vector<char> > &board) {
        vector<bool> col(N, false);
        for (int j = 0; j < N; j++) {
            fill(col.begin(), col.end(), false);
            for (int i = 0; i < N; i++) {
                if (board[i][j] == '.')
                    continue;
                if (col[board[i][j] - '1'])
                    return false;
                col[board[i][j] - '1'] = true;
            }
        }
        return true;
    }

    bool checkSquare(const vector<vector<char> > &board) {
        vector<bool> sqa(N, false);
        int M = N / 3;
        for (int i = 0; i < N; i += M) {
            for (int j = 0; j < N; j += M) {
                fill(sqa.begin(), sqa.end(), false);
                for (int k = i; k < i + M; k++) {
                    for (int l = j; l < j + M; l++) {
                        if (board[k][l] == '.')
                            continue;
                        if (sqa[board[k][l] - '1'])
                            return false;
                        sqa[board[k][l] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};