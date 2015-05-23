class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        if (!len) return s;
        for (int i = len - 1; i >= 0; --i) {
            bool is_palindrom = true;
            for (int j = 0; j <= i/2; ++j) {
                if (s[j] != s[i - j]) {
                    is_palindrom = false;
                    break;
                }
            }
            if (is_palindrom) {
                string add_string = s.substr(i + 1);
                reverse(add_string.begin(), add_string.end());
                return add_string + s;
            }
        }
    }
};
