//one solution
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, result = INT_MIN;
        if(n == 0) return 0;
        for(int i=0; i<n; i++) {
            sum = max(sum + A[i], A[i]);
            result = max(sum, result);
        }
        return result;
    }
};

//记录下当前sum，小于0，则对后面无贡献，归零
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, m;
        if(n == 0) return 0;
        m = A[0];
        for(int i=0; i<n; i++) {
            sum = max(sum, 0);
            sum += A[i];
            m = max(sum, m);
        }
        return m;
    }
};