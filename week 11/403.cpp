#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> posToIndex;
    vector<vector<int>> memo;
    vector<int> stones;
    int n;

    bool dfs(int index, int lastJump) {
        if (index == n - 1) return true;

        if (memo[index][lastJump] != -1) {
            return memo[index][lastJump];
        }

        for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++) {
            if (nextJump <= 0) continue;

            int nextPos = stones[index] + nextJump;

            if (posToIndex.count(nextPos)) {
                int nextIndex = posToIndex[nextPos];

                if (dfs(nextIndex, nextJump)) {
                    return memo[index][lastJump] = true;
                }
            }
        }

        return memo[index][lastJump] = false;
    }

    bool canCross(vector<int>& inputStones) {
        stones = inputStones;
        n = stones.size();

        if (n == 1) return true;
        if (stones[1] != 1) return false;

        for (int i = 1; i < n; i++) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            posToIndex[stones[i]] = i;
        }

        memo.assign(n, vector<int>(n + 1, -1));

        return dfs(0, 0);
    }
};