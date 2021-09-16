//double pointer
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int length = 0;
        for(int i=0; i<n; i++){
            if(A[i] != elem){
                A[length++] = A[i];
            }
        }
        return length;
    }
};