class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size() - 1;
        while (up <= down) {
            int mid = up + (down - up) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) up = mid + 1;
            else down = mid - 1;
        }

        int row = down;
        if (row < 0) return false;

        int l = 0, r = matrix[row].size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};