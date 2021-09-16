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

//Second Try:
class Solution {
public:
    bool canJump(int A[], int n) {
        int max_len = 0;
        int position = 0;
        while(position <= max_len) {
            if(max_len >= n-1) return true;
            max_len = max(position + A[position], max_len);
            position++;
        }
        return false;
    }
};