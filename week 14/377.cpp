#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int sum = 1; sum <= target; sum++) {
            for (int num : nums) {
                if (num > sum) break;
                dp[sum] += dp[sum - num];
            }
        }

        return dp[target];
    }
};