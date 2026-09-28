class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited; 
        for (int r = 0; r < board.size(); r++) {
            vector<bool> temp;
            for (int c = 0; c < board[r].size(); c++) {
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (board[r][c] == word[0]) {
                    bool found = dfs(board, word.substr(1), r,c, visited);
                    if (found) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, vector<vector<bool>>& visited) {
        if (visited[r][c]) {
            return false;
        }
        visited[r][c] = true;
        cout << word << "\n";
        if (word.empty()) {
            return true;
        }
        bool found = false;
        if (r + 1 < board.size() && board[r+1][c] == word[0]) {
            found = dfs(board, word.substr(1), r+1, c, visited);
            cout << "1: \n";
        }
        if (found) {
            return found;
        }
         if (r - 1 > -1 && board[r-1][c] == word[0]) {
            found = dfs(board, word.substr(1), r-1, c, visited);
            cout << "2: \n";
        }
        if (found) {
            return found;
        }
         if (c + 1 < board[r].size() && board[r][c+1] == word[0]) {
            found = dfs(board, word.substr(1), r, c+1, visited);
            cout << "3: \n";
        }
        if (found) {
            return found;
        }
         if (c - 1 > -1 && board[r][c-1] == word[0]) {
            found = dfs(board, word.substr(1), r, c-1, visited);
            cout << "4: \n";
        } 
        visited[r][c] = false;
        return found;
    }
};
