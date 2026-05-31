#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        string t;

        // 壓縮連續重複字元
        for (char c : s) {
            if (t.empty() || t.back() != c) {
                t.push_back(c);
            }
        }

        int n = t.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                // 先假設最後一個字元 t[r] 自己多印一次
                dp[l][r] = dp[l][r - 1] + 1;

                // 如果前面有和 t[r] 相同的字元，就可以合併列印
                for (int k = l; k < r; k++) {
                    if (t[k] == t[r]) {
                        int left = dp[l][k];
                        int middle = (k + 1 <= r - 1) ? dp[k + 1][r - 1] : 0;

                        dp[l][r] = min(dp[l][r], left + middle);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};