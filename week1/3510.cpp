#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> prev(n), nxt(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            nxt[i] = (i + 1 < n) ? i + 1 : -1;
        }

        auto bad = [&](int i, int j) -> int {
            if (i == -1 || j == -1) return 0;
            if (!alive[i] || !alive[j]) return 0;
            return nums[i] > nums[j] ? 1 : 0;
        };

        int badCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) badCount++;
        }

        if (badCount == 0) return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n - 1; i++) {
            pq.push({nums[i] + nums[i + 1], i});
        }

        int ops = 0;

        while (badCount > 0) {
            int pairSum, i, j;

            while (true) {
                pairSum = pq.top().first;
                i = pq.top().second;
                pq.pop();

                j = nxt[i];

                if (alive[i] && j != -1 && alive[j] && nums[i] + nums[j] == pairSum) {
                    break;
                }
            }

            int pi = prev[i];
            int nj = nxt[j];

            badCount -= bad(pi, i);
            badCount -= bad(i, j);
            badCount -= bad(j, nj);

            nums[i] = nums[i] + nums[j];
            alive[j] = false;
            nxt[i] = nj;
            if (nj != -1) {
                prev[nj] = i;
            }

            badCount += bad(pi, i);
            badCount += bad(i, nj);

            if (pi != -1 && alive[pi]) {
                pq.push({nums[pi] + nums[i], pi});
            }
            if (nj != -1 && alive[nj]) {
                pq.push({nums[i] + nums[nj], i});
            }

            ops++;
        }

        return ops;
    }
};