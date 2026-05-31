#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        map<int, int> dp;
        dp[INT_MIN] = 0;

        for (int a : arr1) {
            map<int, int> nextDp;

            for (auto &[prev, cost] : dp) {
                // Case 1: keep arr1[i]
                if (a > prev) {
                    if (!nextDp.count(a)) {
                        nextDp[a] = cost;
                    } else {
                        nextDp[a] = min(nextDp[a], cost);
                    }
                }

                // Case 2: replace arr1[i] with a number from arr2
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int replaceValue = *it;

                    if (!nextDp.count(replaceValue)) {
                        nextDp[replaceValue] = cost + 1;
                    } else {
                        nextDp[replaceValue] = min(nextDp[replaceValue], cost + 1);
                    }
                }
            }

            dp = nextDp;

            if (dp.empty()) {
                return -1;
            }
        }

        int answer = INT_MAX;
        for (auto &[value, cost] : dp) {
            answer = min(answer, cost);
        }

        return answer;
    }
};