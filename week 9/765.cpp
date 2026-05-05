#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i += 2) {
            int first = row[i];
            int partner = first ^ 1;

            if (row[i + 1] != partner) {
                ans++;

                int partnerPos = pos[partner];
                int second = row[i + 1];

                swap(row[i + 1], row[partnerPos]);

                pos[second] = partnerPos;
                pos[partner] = i + 1;
            }
        }

        return ans;
    }
};