#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    int numDecodings(string s) {
        int n = s.size();

        long long prev2 = 1;                 // dp[0]
        long long prev1 = countSingle(s[0]); // dp[1]

        for (int i = 1; i < n; i++) {
            long long cur = 0;

            // s[i] 單獨解碼
            cur += prev1 * countSingle(s[i]);
            cur %= MOD;

            // s[i - 1] 和 s[i] 一起解碼
            cur += prev2 * countDouble(s[i - 1], s[i]);
            cur %= MOD;

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

private:
    long long countSingle(char c) {
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    }

    long long countDouble(char a, char b) {
        if (a == '*' && b == '*') {
            // 11~19 共 9 種，21~26 共 6 種
            return 15;
        }

        if (a == '*') {
            if (b >= '0' && b <= '6') {
                // 10~16 或 20~26
                return 2;
            } else {
                // 17~19
                return 1;
            }
        }

        if (b == '*') {
            if (a == '1') {
                // 11~19
                return 9;
            } else if (a == '2') {
                // 21~26
                return 6;
            } else {
                return 0;
            }
        }

        int num = (a - '0') * 10 + (b - '0');
        return num >= 10 && num <= 26;
    }
};