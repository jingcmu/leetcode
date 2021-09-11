class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        for (int i = 2; i < n; i++) {
            int j = 2;
            while (i * j < n) {
                nums[i * j] = false;
                j ++;
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i]){
                res ++;
            }
        }
        return res;
    }
};