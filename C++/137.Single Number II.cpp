//�������, �����г�2������, ��һ��������д�ü�, ��������û���������ϵĲ��
//��һ��������
//����һ������Ϊsizeof(int) ������count[sizeof(int)]��count[i] ��ʾ����Ԫ
//�ص�1 ��i λ���ֵĴ��������count[i] ��3 ��������������ԣ�
//����ͰѸ�λȡ������ɴ𰸡�
class Solution {
public:
	int singleNumber(int A[], int n) {
		const int W = sizeof(int) * 8; // �����ֳ�
		int count[W]; // ÿ��λ��1 ���ֵĴ���
		fill_n(&count[0], W, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < W; j++) {
				count[j] += (A[i] >> j) & 1;
				count[j] %= 3;
			}
		}
		int result = 0;
		for (int i = 0; i < W; i++) 
		    if(count[i]) result += (1 << i);
		return result;
	}
};

//����2����ones ��¼����ǰ�����Ԫ��Ϊֹ��������1 ���֡�1 �Ρ���mod 3 ֮���1����
//����Щ������λ����twos ��¼����ǰ����ı���Ϊֹ��������1 ���֡�2 �Ρ���mod 3 ֮���2��
//������Щ������λ����ones ��twos �е�ĳһλͬʱΪ1 ʱ��ʾ�ö�����λ��1 ������3 �Σ�
//��ʱ��Ҫ���㡣���ö�����ģ�����������㡣����ones ��¼�������ս����
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int twos = 0, ones = 0, xthrees;
        for(int i=0; i<n; i++){
            twos |= ones&A[i];
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }
};