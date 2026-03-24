class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int sz = 1 << n;                  // 2^n
        vector<vector<int>> ans(sz, vector<int>(sz, 0));
        int cur = 0;
        fill(ans, 0, 0, sz, cur);
        return ans;
    }

private:
    void fill(vector<vector<int>>& grid, int r, int c, int sz, int& cur) {
        if (sz == 1) {
            grid[r][c] = cur++;
            return;
        }

        int half = sz / 2;

        // 順序：右上 -> 右下 -> 左下 -> 左上
        fill(grid, r, c + half, half, cur);         // top-right
        fill(grid, r + half, c + half, half, cur);  // bottom-right
        fill(grid, r + half, c, half, cur);         // bottom-left
        fill(grid, r, c, half, cur);                // top-left
    }
};