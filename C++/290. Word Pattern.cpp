class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s = s + " ";
        int len = s.size();
        
        string sub = "";
        int p_index = 0;
        int p_len = pattern.size();
        unordered_map<string, char> str_map;
        unordered_set<char> c_set;
        
        for(int i=0; i<len; i++) {
            if(s[i] != ' ') {
                sub += s[i];
            } else if(sub.size() != 0) {
                if(p_index >= p_len) {
                    return false;
                }
                if(str_map.find(sub) == str_map.end()) {
                    str_map[sub] = pattern[p_index];
                    if(c_set.find(pattern[p_index]) == c_set.end()) {
                        c_set.insert(pattern[p_index]);
                    } else {
                        return false;
                    }                    
                } else if(str_map[sub] != pattern[p_index]) {
                    return false;
                }
                p_index++;
                sub = "";
            }            
        }
        
        return p_index == p_len;
    }
};