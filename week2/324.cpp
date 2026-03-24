#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int n = nums.size();

        // 左半最後一個位置
        int left = (n - 1) / 2;
        // 右半最後一個位置
        int right = n - 1;

        // 偶數位置放左半（較小值），奇數位置放右半（較大值）
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[left--];
            } else {
                nums[i] = sorted[right--];
            }
        }
    }
};