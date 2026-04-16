class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0);
        int flip = 0;   // 目前位置受到的翻轉次數奇偶
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // 把已經過期的 flip 移除
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }

            // 目前實際值 = nums[i] ^ flip
            if ((nums[i] ^ flip) == 0) {
                // 必須從這裡開始翻
                if (i + k > n) return -1;

                isFlipped[i] = 1;
                flip ^= 1;
                ans++;
            }
        }

        return ans;
    }
};