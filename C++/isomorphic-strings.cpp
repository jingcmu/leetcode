class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap_char;
        unordered_set<char> uset_char;
        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (umap_char.find(s[i]) == umap_char.end()) {
                if (uset_char.find(t[i]) == uset_char.end()) {
                    umap_char[s[i]] = t[i];
                    uset_char.insert(t[i]);
                } else {
                    return false;
                }
            } else if (umap_char[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};