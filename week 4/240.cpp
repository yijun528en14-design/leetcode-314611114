class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int r = 0;
        int c = n - 1;  // 從右上角開始

        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c--;   // 太大，往左
            } else {
                r++;   // 太小，往下
            }
        }

        return false;
    }
};