#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // 目前最小還不能組出的數字
        int i = 0;
        int patches = 0;

        while (miss <= n) {
            // 如果 nums[i] 可以接上目前覆蓋範圍
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i++;
            } 
            // 否則補上 miss 本身
            else {
                miss += miss;
                patches++;
            }
        }

        return patches;
    }
};