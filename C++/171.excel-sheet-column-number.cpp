class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int result = 0, temp;
        for (int i = 0; i < len; i++) {
            temp = (s[i] - 'A') + 1;
            result = result * 26 + temp;
        }
        return result;
    }
};