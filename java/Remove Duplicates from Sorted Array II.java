public class Solution {
    public int removeDuplicates(int[] A) {
        int len = A.length;
        int index = 0;
        if(len <= 2) {
            return len;
        }
        index = 1;
        for(int i=2; i<len; i++) {
            if(A[i] == A[index] && A[i] == A[index-1]) {
                continue;
            }
            else {
                A[++index] = A[i];
            }
        }
        return index+1;
    }
}