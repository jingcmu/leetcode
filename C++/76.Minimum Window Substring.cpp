//����չʾ����ô���������׶���д��һ���õ��㷨����
//�Ѷ����Ĺ����ú�����װ��ȥ�����������ģ�ͻ���С
class Solution {
public:
	//�ж�S�Ƿ��ܰ�סT����T�е��ַ�����ҪС��S�ж�Ӧ���ַ�����
	bool valid(int num1[], int num2[]){
        for(int i=0; i<256; i++){
            if(num1[i]<num2[i]){
                return false;
            }
        }
		return true;
    }
    string minWindow(string S, string T) {
        int s_num[256], t_num[256], c_num[256];
        int lenS = S.length(), lenT = T.length();
        int head = 0, tail = 0, minLen = lenS, head_min=0;
		memset(s_num,0,sizeof(s_num));
		memset(t_num,0,sizeof(s_num));
		memset(c_num,0,sizeof(s_num));
        if(lenS<lenT) return "";
		//ͳ��S�и��ַ��ĸ���
        for(int i=0; i<lenS; i++){
            s_num[S[i]]++;
        }
		//ͳ��T�и��ַ��ĸ���
        for(int i=0; i<lenT; i++) {
            t_num[T[i]]++;
        }
        if(!valid(s_num, t_num)){
            return "";
        }
        c_num[S[0]]++;
        while(tail<lenS){
            //������ܰ�ס,tail����
            if(!valid(c_num, t_num)) {
                c_num[S[++tail]]++;
            }
            //���ȫ��ס,head����
            else{
                if(tail-head+1 < minLen) { //ˢ����Сwindow����
                    minLen = tail-head+1;
                    head_min = head;
                }
                c_num[S[head++]]--;
            }
        }
        return S.substr(head_min, minLen); //������Сwindow
    }
};