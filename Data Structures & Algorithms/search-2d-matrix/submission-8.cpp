class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        vector<int> column;
        for (int i = 0; i < size; i++) {
            column.push_back(matrix[i][0]);
        }
        int col = bSearch(column, target);
        if (col == -1) {
            return false;
        }
        if (matrix[col][0] == target) {
            return true;
        }
        int row = bSearch(matrix[col], target);
        if (matrix[col][row] == target) {
            return true;
        }
        return false;
    }

    int bSearch(vector<int>& vec, int target) {
        int left = 0;
        int right = vec.size() - 1;
        while (right != left) {
            int current = vec[right-left/2];
            if (current == target) {
                return right-left/2;
            } else if (current < target) {
                left = right-left/2 + left;
            } else {
                right = right-left/2 - 1;
            }
        }
        if (target >= vec[left]) {
            return left;
        }
        return -1;
    }
};
