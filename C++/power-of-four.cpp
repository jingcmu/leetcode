class Solution {
public:
    bool isPowerOfFour(int n) {
        while (n && (n & 3) == 0) {
            n = n >> 2;
        }
        return n == 1;
    }
};