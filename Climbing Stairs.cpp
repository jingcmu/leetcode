First Try:
//最简单的动态规划
class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *k = new int[n+1];
        k[1] = 1; k[2] = 2;
        for(int i=3; i<=n; i++){
            k[i] = k[i-1] + k[i-2];
        }
        return k[n];
    }
};

Second Try：
//O(1)的空间复杂度
class Solution {
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int a = 1, b = 2, c;
        if(n==1) return a;
        if(n==2) return b;
        for(int i=3; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};