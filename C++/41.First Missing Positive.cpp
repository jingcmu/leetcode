/*
˼·��
����n����С��0�Ĳ�����ռ��������λ�ã�����ֱ��pass
�������A[i] == i+1��˵�������A[i]��������Ӧ���ڵ�λ�ã�pass
�������A[i] == A[A[i]-1]��˵������Ҫ������pass
������������������򽻻�A[i] �� A[A[i]-1]�����ǰ�A[i]�ŵ���Ӧ���ڵ�λ��
�����������������ϲ���֮���ٴ�ͷ����һ�飬���ص�һ���Ŵ�����λ��
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
