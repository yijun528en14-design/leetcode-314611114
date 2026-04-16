class Solution {
private:
    int bound;
    unordered_map<int, int> mapping;

public:
    Solution(int n, vector<int>& blacklist) {
        bound = n - blacklist.size();

        unordered_set<int> black(blacklist.begin(), blacklist.end());

        int w = bound;  // 從右半邊開始找可用的白名單數字

        for (int b : blacklist) {
            if (b < bound) {
                while (black.count(w)) {
                    w++;
                }
                mapping[b] = w;
                w++;
            }
        }
    }

    int pick() {
        int x = rand() % bound;
        if (mapping.count(x)) return mapping[x];
        return x;
    }
};