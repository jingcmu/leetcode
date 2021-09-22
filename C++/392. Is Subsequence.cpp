class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size()) {
            while (j < t.size()) {
                if (t[j] == s[i]) {                    
                    j++;
                    i++;
                    break;
                } else {
                    j++;
                }
            }
            if (j == t.size()) {
                break;
            }
        }
        return i == s.size();
    }
};