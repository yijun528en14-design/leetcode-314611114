class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};

        while ((int)res.size() < n) {
            vector<int> temp;

            // 先放奇數
            for (int x : res) {
                if (2 * x - 1 <= n) temp.push_back(2 * x - 1);
            }

            // 再放偶數
            for (int x : res) {
                if (2 * x <= n) temp.push_back(2 * x);
            }

            res = temp;
        }

        return res;
    }
};