class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // 找到一個完整的 special substring
            if (count == 0) {
                // 去掉最外層的 1 和 0，裡面遞迴處理
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // 由大到小排序，讓字典序最大
        sort(parts.begin(), parts.end(), greater<string>());

        string result;
        for (string& part : parts) {
            result += part;
        }

        return result;
    }
};