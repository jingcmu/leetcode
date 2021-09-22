class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;
        for (int i = 0; i < s.size(); i++) {
            if (map_s.find(s[i]) == map_s.end()) {
                map_s[s[i]] = 1;
            } else {
                map_s[s[i]] ++;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (map_t.find(t[i]) == map_t.end()) {
                map_t[t[i]] = 1;
            } else {
                map_t[t[i]] ++;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (map_s.find(t[i]) == map_s.end()) {
                return t[i];
            }
            if (map_t[t[i]] > map_s[t[i]]) {
                return t[i];
            }
        }
        return ' ';
    }
};