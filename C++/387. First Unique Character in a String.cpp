class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map_s;
        for (int i = 0; i < s.size(); i++) {
            if (map_s.find(s[i]) == map_s.end()) {
                map_s[s[i]] = 1;
            } else {
                map_s[s[i]] ++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (map_s[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};