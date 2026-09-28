class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int r = 0; r <board.size(); r++) {
            unordered_set<char> vals;
            for (int c = 0; c < board[0].size(); c++) {
                if (vals.count(board[r][c])) {
                    return false;
                } else {
                    if (board[r][c] != '.') {
                        vals.insert(board[r][c]);
                    }
                }
            }
        }
        for (int c = 0; c < board[0].size(); c++) {
            unordered_set<char> vals;
            for (int r = 0; r <board.size(); r++) { 
                if (vals.count(board[r][c])) {
                    return false;
                } else {
                    if (board[r][c] != '.') {
                        vals.insert(board[r][c]);
                    }
                }
            }
        }
        for (int r = 0; r < board.size(); r +=3) {
            for (int c = 0; c < board[0].size(); c +=3) {
                if (!square(board,r,c)) {
                    return false;
                }
            }
        }
        return true;


        
    }

    bool square(vector<vector<char>>& board, int r, int c) {
        unordered_set<char> vals;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (vals.count(board[r+i][c+j])) {
                    return false;
                } else {
                    if (board[r+i][c+j] != '.') {
                        vals.insert(board[r+i][c+j]);
                    }
                }
            }
        }
        return true;
    }
};
