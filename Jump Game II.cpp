class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int longest, step = 1;
        int i = 0;
        if(!n || n == 1){
            return 0;
        }
        longest = A[0];
        while(longest < n-1){
            int l = longest;
            while(i <= l){
                if(i+A[i] > longest){
                    longest = i+A[i];
                }
                i++;
            }
            step++;
        }
        return step;
    }
};