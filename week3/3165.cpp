class Solution {
public:
    static constexpr long long NEG = -(1LL << 60);
    static constexpr int MOD = 1e9 + 7;

    struct Node {
        long long dp[2][2];
        Node() {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    dp[i][j] = NEG;
                }
            }
        }
    };

    vector<Node> seg;
    int n;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                if (L.dp[a][b] == NEG) continue;
                for (int c = 0; c < 2; c++) {
                    for (int d = 0; d < 2; d++) {
                        if (R.dp[c][d] == NEG) continue;
                        if (b == 1 && c == 1) continue; // 相鄰不能同時選
                        res.dp[a][d] = max(res.dp[a][d], L.dp[a][b] + R.dp[c][d]);
                    }
                }
            }
        }
        return res;
    }

    Node makeLeaf(int x) {
        Node node;
        node.dp[0][0] = 0;   // 不選
        node.dp[1][1] = x;   // 選
        return node;
    }

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[idx] = makeLeaf(nums[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(idx << 1, l, mid, nums);
        build(idx << 1 | 1, mid + 1, r, nums);
        seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = makeLeaf(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(idx << 1, l, mid, pos, val);
        else update(idx << 1 | 1, mid + 1, r, pos, val);
        seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());
        build(1, 0, n - 1, nums);

        long long ans = 0;
        for (auto& q : queries) {
            int pos = q[0], x = q[1];
            update(1, 0, n - 1, pos, x);

            long long best = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    best = max(best, seg[1].dp[i][j]);
                }
            }
            ans = (ans + best) % MOD;
        }
        return (int)ans;
    }
};