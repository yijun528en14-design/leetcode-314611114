#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;

        // 合併右端連續相同顏色
        while (l < r && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }

        if (dp[l][r][k] != 0) {
            return dp[l][r][k];
        }

        // 情況 1：直接刪掉 boxes[r] 加上右邊 k 個同色盒子
        int ans = solve(boxes, l, r - 1, 0) + (k + 1) * (k + 1);

        // 情況 2：找前面同色盒子，讓它跟 boxes[r] 合併
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                ans = max(ans,
                    solve(boxes, l, i, k + 1) +
                    solve(boxes, i + 1, r - 1, 0)
                );
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        int n = boxes.size();

        return solve(boxes, 0, n - 1, 0);
    }
};