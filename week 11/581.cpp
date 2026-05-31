#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;

        int maxVal = nums[0];

        // 從左到右找右邊界
        for (int i = 1; i < n; i++) {
            if (nums[i] < maxVal) {
                right = i;
            } else {
                maxVal = nums[i];
            }
        }

        int minVal = nums[n - 1];

        // 從右到左找左邊界
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minVal) {
                left = i;
            } else {
                minVal = nums[i];
            }
        }

        if (left == -1) return 0;

        return right - left + 1;
    }
};