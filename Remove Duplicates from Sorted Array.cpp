//double pointer
class Solution {
public :
    int removeDuplicates( int A[], int n) {
        int length = 1;
        if(!n) return 0;
        for( int i=1; i<n; i++){
            if(A[i] != A[i-1]){
               A[length++] = A[i]; 
            }
        }
        return length;
    }
};
