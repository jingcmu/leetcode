class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long i = 1; i <= num; i++) {
            long long ii = (long long)i * i;
            if (ii == num) {
                return true;
            }
            if (ii > num) {
                return false;
            }
        }
        return false;
    }
};