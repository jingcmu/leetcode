class Solution {
public :
    int firstMissingPositive( int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 0;
        while(i < n){
            if(A[i] == i+1 || A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1]){
                i++;
            }
            else{  //swap two number without using extra space
                swap(A[i], A[A[i]-1]);
            }
        }
        for(i=0; i<n; i++){
            if(A[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
