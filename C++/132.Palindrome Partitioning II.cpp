//��̬�滮���жϻ���Ҳ�ö��棬�ǳ�������⣬״̬ת�Ʒ��̺ܲ���
class Solution {  
public:  
	//res[i] ����[i,n]֮����С��cut����nΪ�ַ������ȣ���
	//res[i] = min(1+res[j+1], res[i] ) �� i<=j <n����s[i..j]�ǻ���
	//��Ϊ�����Դ�j����ָj+1��n��֮ǰ�ֹ��ˣ������⣩
    int minCut(string s) {  
        int n = s.size();  
        vector<int > res(n+1);  
        vector<vector<bool> > p(n, vector<bool>(n, false));  
        for(int i = 0; i <= n; ++i) {  
            res[i] = n - i - 1; //����res[0]��ʼӦ��ʼ��Ϊn-1�� 
        } 
		//�Ӻ���ǰ��
        for(int i = n - 1; i >=0; --i) {  
            for(int j = i; j < n; ++j) {  
                if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) { //�жϻ���
                    p[i][j] = true; //s[i..j]�ǻ���
                    res[i] = min(res[i], res[j + 1] + 1);  
                }  
            }  
        }  
        return res[0];  
    }  
};