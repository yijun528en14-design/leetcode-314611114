#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;  // 指向 s
        int j = 0;  // 指向 p

        int starIdx = -1;   // 記錄上一個 * 的位置
        int matchIdx = 0;   // 記錄 * 開始匹配 s 的位置

        while (i < s.size()) {
            // 1. 字元相同，或 p[j] 是 ?
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            // 2. 遇到 *
            else if (j < p.size() && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++;
            }
            // 3. 配不起來，但前面有 *
            else if (starIdx != -1) {
                j = starIdx + 1;
                matchIdx++;
                i = matchIdx;
            }
            // 4. 配不起來，也沒有 * 可以用
            else {
                return false;
            }
        }

        // s 已經配完，p 剩下的必須全部都是 *
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};