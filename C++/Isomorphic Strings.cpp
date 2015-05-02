class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m1, m2;
        if (s.length() != t.length()) return false;
        for (int i = 0; i < s.length(); ++i) {
            if (m1.find(s[i]) == m1.end()) {
                m1[s[i]] = t[i];
            } else {
                if (m1[s[i]] != t[i]) {
                    return false;
                }
            }
            if (m2.find(t[i]) == m2.end()) {
                m2[t[i]] = s[i];
            } else {
                if (m2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
