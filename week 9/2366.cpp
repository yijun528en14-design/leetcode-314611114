#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        long long limit = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            long long x = nums[i];

            if (x <= limit) {
                limit = x;
            } else {
                long long parts = (x + limit - 1) / limit;
                ans += parts - 1;

                limit = x / parts;
            }
        }

        return ans;
    }
};