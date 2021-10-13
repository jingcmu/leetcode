class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        
        while (n > 1) {
            res += (n / 2);
            n = (n + (n & 0x1)) / 2;
        }
        
        return res;
    }
};