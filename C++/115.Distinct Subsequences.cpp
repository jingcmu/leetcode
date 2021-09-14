/*
�ַ���������ܶ඼����ʹ�ö�̬�滮��
��״̬Ϊf(i,j)����ʾT[0,j]��S[0,i]����ֵĴ��������ȣ�����S[i]��T[j]��
����ȣ�����ʹ��S[i]����f(i,j) = f(i-1,j)����S[i]==T[j]�������ʹ��S[i]����ʱ
f(i,j) = f(i-1,j) + f(i-1,j-1)��f(i-1,j)����ʹ��S[i]��f(i-1,j-1)����ʹ��S[i]
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.length();
        int lenT = T.length();
        if(lenS < lenT) return 0;
        vector<vector<int> > res(lenS, vector<int>(lenT, 0));
        if(S[0] == T[0]) res[0][0] = 1;
		//��ʼ����һ�У���һ�ж���0����Ҫ�����ʼ��
        for(int i=1; i<lenS; i++){
            if(S[i] == T[0]){
                res[i][0] = res[i-1][0] + 1;
            }
            else{
				res[i][0] = res[i-1][0];
			}
        }
        for(int i=1; i<lenS; i++){
            for(int j=1; j<lenT; j++){
				//����״̬ת�Ʒ���...
                if(S[i] == T[j]){
                    res[i][j] = res[i-1][j] + res[i-1][j-1];
                }
                else{
                    res[i][j] = res[i-1][j];
                }
            }
        }
        return res[lenS-1][lenT-1];
    }
};

// ��ά����+ ��������
// ʱ�临�Ӷ�O(m*n)���ռ临�Ӷ�O(n)
class Solution {
public:
	int numDistinct(const string &S, const string &T) {
		vector<int> f(T.size() + 1);
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i) {
			for (int j = T.size() - 1; j >= 0; --j) {
				f[j + 1] += S[i] == T[j] ? f[j] : 0;
			}
		}
		return f[T.size()];
	}
};