//贪心法
class Solution {
public:
    bool canJump(int A[], int n) {
        int longest;
        if(n == 0) return true;
        longest = A[0];
        for(int i=1; i<n; i++){
            if(i>longest) return false;
			//贪心法：当前最远能走多远
            if(A[i] + i > longest){
                longest = A[i]+i;
            }
        }
        return true;
    }
};