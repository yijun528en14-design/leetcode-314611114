#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // 用 long long 存目前數值，避免合併後爆 int
        vector<long long> a(nums.begin(), nums.end());

        vector<int> prev(n), nxt(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            nxt[i] = (i + 1 < n) ? i + 1 : -1;
        }

        auto bad = [&](int i, int j) -> int {
            if (i == -1 || j == -1) return 0;
            if (!alive[i] || !alive[j]) return 0;
            return a[i] > a[j] ? 1 : 0;
        };

        int badCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) badCount++;
        }

        if (badCount == 0) return 0;

        // pairSum 改成 long long
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({a[i] + a[i + 1], i});
        }

        int ops = 0;

        while (badCount > 0) {
            long long pairSum;
            int i, j;

            while (true) {
                pairSum = pq.top().first;
                i = pq.top().second;
                pq.pop();

                j = nxt[i];

                if (alive[i] && j != -1 && alive[j] && a[i] + a[j] == pairSum) {
                    break;
                }
            }

            int pi = prev[i];
            int nj = nxt[j];

            badCount -= bad(pi, i);
            badCount -= bad(i, j);
            badCount -= bad(j, nj);

            // 合併也用 long long
            a[i] = a[i] + a[j];
            alive[j] = false;
            nxt[i] = nj;
            if (nj != -1) {
                prev[nj] = i;
            }

            badCount += bad(pi, i);
            badCount += bad(i, nj);

            if (pi != -1 && alive[pi]) {
                pq.push({a[pi] + a[i], pi});
            }
            if (nj != -1 && alive[nj]) {
                pq.push({a[i] + a[nj], i});
            }

            ops++;
        }

        return ops;
    }
};
