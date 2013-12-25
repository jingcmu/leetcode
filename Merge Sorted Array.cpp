First Try:
//from back to front
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
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

Second Try:
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int length = m+n;
        int i, j, k, t;
        for(i=length-1, j=m-1, k=n-1; i>=0; i--){
            if(k<0) break;
            if(j >= 0 && A[j] > B[k]){
                A[i] = A[j--];
            }
            else{
                A[i] = B[k--];
            }
        }
    }
};

Better Solution:
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int ia = m - 1, ib = n - 1, icur = m + n - 1;
		while(ia >= 0 && ib >= 0) {
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
		}
		while(ib >= 0) {
			A[icur--] = B[ib--];
		}
	}
};