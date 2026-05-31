#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;   // 總油量差
        int tank = 0;    // 從目前起點開始的油箱油量
        int start = 0;   // 可能的起點

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];

            total += diff;
            tank += diff;

            // 如果目前油量變成負數，代表 start 到 i 都不能當起點
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // 總油量不夠，無解
        if (total < 0) {
            return -1;
        }

        return start;
    }
};