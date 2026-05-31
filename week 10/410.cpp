#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int count = 1;          // 至少有一段
        long long current = 0;  // 目前這一段的總和

        for (int num : nums) {
            // 如果加進來會超過 maxSum，就開新的一段
            if (current + num > maxSum) {
                count++;
                current = num;
            } else {
                current += num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = 0;
        long long right = 0;

        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                // mid 可行，試試看更小的答案
                right = mid;
            } else {
                // mid 太小，要放大
                left = mid + 1;
            }
        }

        return left;
    }
};