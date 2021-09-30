class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        
        while (n) {
            int t = n % 10;
            product *= t;
            sum += t;
            n /= 10;
        }
        
        return product - sum;
    }
};