#include <vector>
using namespace std;

class Solution {
public:
    vector<int> temp;

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = 0;

        // 遞迴處理左右兩半
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);

        // 計算跨左右兩半的 reverse pairs
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        // 合併兩個已排序區間
        int p1 = left;
        int p2 = mid + 1;
        int k = left;

        while (p1 <= mid && p2 <= right) {
            if (nums[p1] <= nums[p2]) {
                temp[k++] = nums[p1++];
            } else {
                temp[k++] = nums[p2++];
            }
        }

        while (p1 <= mid) {
            temp[k++] = nums[p1++];
        }

        while (p2 <= right) {
            temp[k++] = nums[p2++];
        }

        // 複製回原陣列
        for (int i = left; i <= right; i++) {
            nums[i] = temp[i];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        temp.resize(nums.size());
        return mergeSort(nums, 0, nums.size() - 1);
    }
};