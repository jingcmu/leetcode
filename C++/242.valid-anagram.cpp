class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        if(len_s != len_t) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};