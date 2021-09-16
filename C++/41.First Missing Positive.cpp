/*
思路：
大于n或者小于0的不可能占据正数的位置，所以直接pass
如果遇到A[i] == i+1，说明这个数A[i]正好在它应该在的位置，pass
如果遇到A[i] == A[A[i]-1]，说明不需要交换，pass
如果不是上面的情况，则交换A[i] 和 A[A[i]-1]，就是把A[i]放到它应该在的位置
对所有数进行了以上操作之后，再从头遍历一遍，返回第一个放错数的位置
*/
class Solution {
public :
    int firstMissingPositive( int A[], int n) {
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
