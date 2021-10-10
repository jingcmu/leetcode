class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int index = 0;
        int cap = s.size();
        int balanced = 0;
        
        while (index < cap) {
            if (s[index++] == 'R') {
                balanced --;
            } else {
                balanced ++;
            }
            if (balanced == 0) {
                res ++;
            }
        }
        
        return res;
    }
};