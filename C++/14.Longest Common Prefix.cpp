//��λ��0 ��ʼ����ÿһ��λ�ñȽ������ַ���������һ���ַ����ȣ���ֱ������һ����ƥ�䡣
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string str=""; //�湫��ǰ׺
        bool flag = true;
		if(strs.empty()) return str;
        for(int i=0; i<strs[0].length(); i++){
            for(int j=1; j<strs.size(); j++){
                //ÿ��������һ���ַ����Ƚ�
                if(strs[j].length() < i || strs[j][i] != strs[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) str += strs[0][i];
            else break;
        }
        return str;
    }
};