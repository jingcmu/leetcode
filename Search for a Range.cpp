class Solution {
public:
    void searchRange(vector<int> &v, int A[], int cur, int n, int target){
        for(int i=cur; i>=0; i--){
            if(A[i] == target){
                v[0] = i;
            }
            else{
                break;
            }
        }
        for(int i=cur; i<n; i++){
            if(A[i] == target){
                v[1] = i;
            }
            else{
                break;
            }
        }
        return;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        int head = 0, tail = n-1, cur=(head+tail)>>1;
        v.resize(2);
        v[0] = v[1] = -1;
        if(n==0) {
            return v;
        }
        if(n==1 && A[0] == target){
            v[0] = v[1] = 0;
            return v;
        }
        while(head < tail){
            if(cur == head || cur == tail){
                if(A[head] == target){
                    cur = head;
                }
                else if(A[tail] == target){
                    cur = tail;
                }
                searchRange(v,A,cur,n,target);
                return v;
            }
            if(A[cur] > target){
                tail = cur;
            }
            else if(A[cur] < target){
                head = cur;
            }
            else{
                searchRange(v,A,cur,n,target);
                return v;
            }
            cur = (head+tail)>>1;
        }
        return v;
    }
};