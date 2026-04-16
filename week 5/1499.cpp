class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq; // {x_i, y_i - x_i}
        int ans = INT_MIN;

        for (auto& p : points) {
            int x = p[0], y = p[1];

            // 移除不符合 xj - xi <= k 的點
            while (!dq.empty() && x - dq.front().first > k) {
                dq.pop_front();
            }

            // 用目前最佳的 (y_i - x_i) 更新答案
            if (!dq.empty()) {
                ans = max(ans, x + y + dq.front().second);
            }

            int val = y - x;

            // 維持 deque 單調遞減
            while (!dq.empty() && dq.back().second <= val) {
                dq.pop_back();
            }

            dq.push_back({x, val});
        }

        return ans;
    }
};