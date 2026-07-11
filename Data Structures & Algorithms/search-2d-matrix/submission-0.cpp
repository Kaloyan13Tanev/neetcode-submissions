class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0; int down = matrix.size() - 1;
        int mid = (down - up) / 2 + up;
        while (up <= down)
        {
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target)
            {
                up = mid + 1;
            }
            else down = mid - 1;

            mid = (down - up) / 2 + up;
        }

        int i = up > 0 ? up - 1 : up;
        int l = 0; int r = matrix[i].size() - 1;
        mid = (r - l) / 2 + l;
        while (l <= r)
        {
            if (matrix[i][mid] == target) return true;
            else if (matrix[i][mid] < target)
            {
                l = mid + 1;
            }
            else r = mid - 1;

            mid = (r - l) / 2 + l;
        }

        return false;
    }
};
