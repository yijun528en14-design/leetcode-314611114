#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;
        long long f = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;

        for (int k = 1; k < n; k++) {
            f = f + total - 1LL * n * nums[n - k];
            ans = max(ans, f);
        }

        return ans;
    }
};