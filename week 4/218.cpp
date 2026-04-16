class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        // 建立事件點
        for (auto& b : buildings) {
            int L = b[0], R = b[1], H = b[2];
            events.push_back({L, -H}); // start
            events.push_back({R, H});  // end
        }

        // 先依 x 排序
        // 同 x 時：
        // 1. start(-H) 會比 end(H) 先處理
        // 2. start 中較高的先處理，例如 -15 < -10
        // 3. end 中較低的先處理，例如 10 < 15
        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0); // 地面高度

        int prevMax = 0;
        vector<vector<int>> ans;

        for (auto& e : events) {
            int x = e.first;
            int h = e.second;

            if (h < 0) {
                // 建築開始
                heights.insert(-h);
            } else {
                // 建築結束
                heights.erase(heights.find(h));
            }

            int currMax = *heights.rbegin();

            if (currMax != prevMax) {
                ans.push_back({x, currMax});
                prevMax = currMax;
            }
        }

        return ans;
    }
};