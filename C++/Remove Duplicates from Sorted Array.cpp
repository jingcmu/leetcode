First Try:
//double pointer, 注意n为0的情况
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

Second Try:
//一种奇特的方法
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return distance(A, unique(A, A + n));
    }
};
注：distance返回两个迭代器的距离，unique函数把相邻的重复元素移到末尾，返回交界位置