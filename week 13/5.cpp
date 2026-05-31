class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            // 奇數長度回文，例如 "bab"
            expand(s, i, i, start, maxLen);

            // 偶數長度回文，例如 "abba"
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

    void expand(string& s, int left, int right, int& start, int& maxLen) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;

            if (len > maxLen) {
                start = left;
                maxLen = len;
            }

            left--;
            right++;
        }
    }
};