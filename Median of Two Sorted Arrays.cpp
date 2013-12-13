class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total & 0x1) { //奇数个元素,取中间元素
            return find_kth(A, m, B, n, total/2 + 1);
        }
        else { //偶数个元素,取中间两个元素的平均
            return (find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2 + 1))/2;
        }
    }
private:
    double find_kth(int A[], int m, int B[], int n, int k) {
        if(m > n) return find_kth(B, n, A, m, k); //假定m小于等于n
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        
        int pa = min(k/2, m), pb = k - pa; //二分法的变形
        if(A[pa-1] < B[pb-1]) { //去掉A的k/2个元素或者全部
            return find_kth(A+pa, m-pa, B, n, k-pa);
        }
        else if(A[pa-1] > B[pb-1]) { //去掉B的k/2个元素或者更多个元素
            return find_kth(A, m, B+pb, n-pb, k-pb);
        }
        else {
            return A[pa-1];
        }
    }
}; 