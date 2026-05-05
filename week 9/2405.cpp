#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        vector<bool> used(26, false);
        int ans = 1;

        for (char c : s) {
            int idx = c - 'a';

            if (used[idx]) {
                ans++;
                fill(used.begin(), used.end(), false);
            }

            used[idx] = true;
        }

        return ans;
    }
};