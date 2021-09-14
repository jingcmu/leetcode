/*
��ά��̬�滮��
��״̬Ϊf[i][j]����ʾA[0,i] ��B[0,j] ֮�����С�༭���롣
��A[0,i] ����ʽ��str1c��B[0,j] ����ʽ��str2d��
1. ���c==d����f[i][j]=f[i-1][j-1]������������
2. ���c!=d��
(a) �����c �滻��d����f[i][j]=f[i-1][j-1]+1�� ��������ڶ���
(b) �����c �������һ��d����f[i][j]=f[i][j-1]+1��ע������c�������d������ǰ��
(c) �����c ɾ������f[i][j]=f[i-1][j]+1��
*/
class Solution {
public:
    #define min(a,b,c) min(a,min(b,c))
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int> > matrix(len1+1, vector<int>(len2+1));
		//��ʼ������word1�Ŀմ���word2����С�༭����
        for(int i=0; i<=len2; i++){
            matrix[0][i] = i;
        }
		//��ʼ������word2�Ŀմ���word1����С�༭����
        for(int i=0; i<=len1; i++){
            matrix[i][0] = i;
        }
		//ȡ4���������Сֵ
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                int flag = (word1[i-1]==word2[j-1]?0:1);
                matrix[i][j] = min(matrix[i-1][j]+1,matrix[i][j-1]+1,
                                   matrix[i-1][j-1]+flag );
            }
        }
		//����A[0,len1]��B[0,len2]�ı༭����
        return matrix[len1][len2];
    }
};