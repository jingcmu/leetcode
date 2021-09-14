/*
˼·��
�����뵽���ǵݹ飨�����ѣ���������string ���зָȻ��Ƚ��Ķ��ַ�����������Ȼ�򵥣�
���Ǹ��ӶȱȽϸߡ������ּ��ٲ��ԣ�һ���Ǽ�֦����ǰ���أ�һ���Ǽӻ��棬�����м�������
memorization������Ϊ���仯��������
��֦�����廨���ţ�Ҫ��ֹ۲죬���������Ϣ���ҵ����ýڵ���ǰ���ص����������磬�ж�
�����ַ����Ƿ�Ϊscamble������Ҫ��ÿ���ַ��������ַ����г��ֵĴ���Ҫ��ȣ���������
�򷵻�false��
�ӻ��棬�����������HashMap������ά���ϸߣ���HashMap��map ��unordered_map ���ɡ�
��Ȼ�����ü��仯����������Ҳһ�������ö��档��״̬Ϊf[n][i][j]����ʾ����Ϊn����
��Ϊs1[i] �����Ϊs2[j] �����ַ����Ƿ�Ϊscramble����״̬ת�Ʒ���Ϊ
f[n][i][j] = (f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j])
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if(len != s2.length()) return false;
        bool res[len+1][len][len];
        memset(res, false, sizeof(bool)*(len+1)*len*len);
		//��ʼ��
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                res[1][i][j] = s1[i]==s2[j]; //����Ϊ1�����Ϊs1[i]��s2[j]���ַ����Ƿ�Ϊscramble
            }
        }
        
        for(int l=2; l<=len; l++){ //l stand for length
            for(int i=0; i<=len-l; i++){  //ע����ںţ�s1�����
                for(int j=0; j<=len-l; j++){ //s2�����
                    for(int divlen=1; divlen<l && !res[l][i][j]; divlen++){ //�����ָ��
                        if((res[divlen][i][j] && res[l-divlen][i+divlen][j+divlen]) 
                            || (res[divlen][i][j+l-divlen] && res[l-divlen][i+divlen][j])){
                            res[l][i][j] = true;
                            break;   //��һ��true�Ϳ�����
                        }
                    }
                }
            }
        }
        return res[len][0][0];
    }
};