First Try:
//double pointer, ע��nΪ0�����
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
//һ�����صķ���
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        return distance(A, unique(A, A + n));
    }
};
ע��distance���������������ľ��룬unique���������ڵ��ظ�Ԫ���Ƶ�ĩβ�����ؽ���λ��