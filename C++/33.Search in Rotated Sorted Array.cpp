//���ַ����ҵı���, ʱ�临�Ӷ�log n
//�ֱ����۸������
//����ͨ���ֲ��ҵ������ǣ���ͨ���ַ�ֻ��Ҫ��target��midλ�õ����ȽϾͿ����ų�һ��Ԫ��
//�����������жϳ��Ǳ��������ĶΣ�Ȼ���ж�target�Ƿ��������Ķ��У������ų�һ��Ԫ��
//��Ϊ������õ������ĶΣ���û�������ж�
class Solution {
public:
	int search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target)
				return mid;
			//������������
			if (A[first] <= A[mid]) {
				//�ж�target�Ƿ������
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} 
			//�ұ���������
			else {
				//�ж�target�Ƿ����Ҷ�
				if (A[mid] < target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};

second try:
public class Solution {
    //���ֲ���
    int search(int A[], int n, int target) {  
        int start = 0,end = n-1;  
        int mid;  
        while(start <= end){  
            mid = (start + end) / 2;  
            if(A[mid] == target){  
                return mid;  
            }  
            //�м�Ԫ�ش��������Ԫ�����󲿷�Ϊ��������  
            else if(A[mid] >= A[start]){  
                //Ŀ��λ���󲿷�  
                if(target >= A[start] && target <= A[mid]){  
                    end = mid - 1;  
                }  
                //Ŀ��λ���Ҳ���  
                else{  
                    start = mid + 1;  
                }  
            }  
            //�м�Ԫ��С�����ұ�Ԫ�����Ҳ���Ϊ��������  
            else{  
                //Ŀ��λ���󲿷�  
                if(target <= A[end] && target >= A[mid]){  
                    start = mid + 1;  
                }  
                //Ŀ��λ���󲿷�  
                else{  
                    end = mid - 1;  
                }  
            }  
        }  
        return -1;  
    }  
}