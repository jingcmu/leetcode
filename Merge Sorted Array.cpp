//from back to front
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int length = m+n;
        int i, j, k, t;
        for(i=length-1, j=m-1, k=n-1; i>=0; i--){
            if(j < 0){
                for(t=k; t>=0; t--){
                    A[i--] = B[t];
                }
                return;  
            } 
            if(k < 0){
                for(t=j; t>=0; t--){
                    A[i--] = A[t];
                }
                return;
            }
            if(A[j] > B[k]){
                A[i] = A[j--];
            }
            else{
                A[i] = B[k--];
            }
        }
    }
};
