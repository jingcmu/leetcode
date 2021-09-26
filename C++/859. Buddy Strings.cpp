class Solution {
private:
    bool containSameChar(string s) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (s[i] == s[j]) {
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    bool buddyStrings(string s, string goal) {
        int size = s.size();
        if (size != goal.size()) {
            return false;
        }
        
        int left, right, diff;
        left = right = -1;
        diff = 0;
        
        for (int i = 0; i < size; i++) {
            if (s[i] != goal[i]) {
                diff ++;
                if (left == -1) {
                    left = i;
                } else {
                    right = i;
                }
            }
        }
        
        return (diff == 0 && containSameChar(s)) ||
            (diff == 2 && s[left] == goal[right] && s[right] == goal[left]);
    }
};