class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int pos_target = -1;
        for(int i=0; i<n; i++){
            if(A[i] == target){
                pos_target = i;
            }
        }
        return pos_target;
    }
};