class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        unordered_map<char, int> map_m;
        for (int i = 0; i < magazine.size(); i++) {
            if (map_m.find(magazine[i]) == map_m.end()) {
                map_m[magazine[i]] = 1;
            } else {
                map_m[magazine[i]] ++;
            }
        }
        unordered_map<char, int> map_r;
        for (int i = 0; i < ransomNote.size(); i++) {
            if (map_r.find(ransomNote[i]) == map_r.end()) {
                map_r[ransomNote[i]] = 1;
            } else {
                map_r[ransomNote[i]] ++;
            }
            if (map_m.find(ransomNote[i]) == map_m.end() ||
               map_m[ransomNote[i]] < map_r[ransomNote[i]]) {
                return false;
            }
        }
        return true;
    }
};