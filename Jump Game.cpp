class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int longest;
        if(n == 0){
            return true;
        }
        longest = A[0];
        for(int i=1; i<n-1; i++){
            if(i>longest){
                return false;
            }
            if(A[i] + i > longest){
                longest = A[i]+i;
            }
        }
        if(longest >= n-1){
            return true;
        }
        else{
            return false;
        }
    }
};