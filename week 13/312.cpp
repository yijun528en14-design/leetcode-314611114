class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        arr.push_back(1);

        for (int x : nums) {
            arr.push_back(x);
        }

        arr.push_back(1);

        int m = arr.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int left = 0; left + len < m; left++) {
                int right = left + len;

                for (int k = left + 1; k < right; k++) {
                    int coins = dp[left][k]
                              + arr[left] * arr[k] * arr[right]
                              + dp[k][right];

                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        return dp[0][m - 1];
    }
};