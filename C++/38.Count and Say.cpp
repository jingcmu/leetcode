//ģ��
/*
�����ַ�����ģ�����Ķ����������м��������ģ���¼������Ȼ�󷵻��ַ���
*/
class Solution {
public:
    string countAndSay(string str){
        string s = "";
        int count, len = str.length();
        count = 1;
        for(int i=0; i<=len-1; i++){
            if(i<len-1 && str[i] == str[i+1]){
                count++; //��¼�м����������ַ�
            }
            else{
                s += (char)(count+48);
                s += str[i];
                count = 1;
            }
        }
        return s;
    }
    string countAndSay(int n) {
        string s_res = "1";
        for(int i=2; i<=n; i++){
            s_res = countAndSay(s_res);
        }
        return s_res;
    }
};