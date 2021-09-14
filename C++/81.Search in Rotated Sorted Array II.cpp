//�����ظ�Ԫ�أ�����һ�������A[m]>=A[l], ��ô[l,m] Ϊ�������еļ���Ͳ��ܳ����ˣ���
//��[1,3,1,1,1]��
//���A[m]>=A[l] ����ȷ���������ǾͰ�����ֳ�����������
//��A[m]>A[l]��������[l,m] һ������
//��A[m]==A[l] ȷ�����ˣ��Ǿ�l++������������ߵ��ظ�Ԫ��
//����Ȼ���ⲻ��Ӱ����
class Solution {
public:
	bool search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target) return true;		
			if (A[first] < A[mid]) {
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} else if (A[first] > A[mid]) {
				if (A[mid] <= target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			} else
				//�����ظ�Ԫ��, A[start] == A[mid]
				first++;
		}
		return false;
	}
};