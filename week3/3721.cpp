class Solution {
public:
    struct Node {
        int l, r;
        int mn, mx, lazy;
    };

    vector<Node> tr;

    void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        tr[u].mn = tr[u].mx = tr[u].lazy = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void apply(int u, int v) {
        tr[u].mn += v;
        tr[u].mx += v;
        tr[u].lazy += v;
    }

    void pushdown(int u) {
        if (tr[u].lazy != 0) {
            apply(u << 1, tr[u].lazy);
            apply(u << 1 | 1, tr[u].lazy);
            tr[u].lazy = 0;
        }
    }

    void pushup(int u) {
        tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }

    void modify(int u, int l, int r, int v) {
        if (l > r) return;
        if (tr[u].l >= l && tr[u].r <= r) {
            apply(u, v);
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }

    int query(int u, int target) {
        if (tr[u].l == tr[u].r) return tr[u].l;
        pushdown(u);
        if (tr[u << 1].mn <= target && target <= tr[u << 1].mx) {
            return query(u << 1, target);
        }
        return query(u << 1 | 1, target);
    }

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        tr.resize((n + 1) * 4 + 5);
        build(1, 0, n);

        unordered_map<int, int> last;
        int now = 0, ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int det = (x & 1) ? 1 : -1;  // odd -> +1, even -> -1

            if (last.count(x)) {
                modify(1, last[x], n, -det);
                now -= det;
            }

            last[x] = i;
            modify(1, i, n, det);
            now += det;

            int pos = query(1, now);
            ans = max(ans, i - pos);
        }

        return ans;
    }
};