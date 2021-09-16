class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string d[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, str;
        int len[8] = {3,3,3,3,3,4,3,4}, len_i = digits.length();
        vector<string> vs;
        vs.clear();
        if(len_i == 0){
            vs.push_back("");
            return vs;
        }
		//�Ȱѵ�һ�����ּ��ϵ���ĸpush�����
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs.push_back(str);
        }
		/*
		��ÿ��vector�е�Ԫ�أ������׷���¸����ּ��ϵ�ÿ����ĸ��
		��push��vector��Ȼ����ϵ�Ԫ��ȫ�����
		*/
        for(int i=1; i<len_i; i++){
            int size = vs.size();
            for(int j=0; j<size; j++){
                for(int k=0; k<len[digits[i]-'2']; k++){
                    str = vs[j]+d[digits[i]-'2'][k];
                    vs.push_back(str);
                }
            }
            vs.erase(vs.begin(), vs.begin()+size);
        }
        return vs;
    }
};

//����д�������ǲ��Ǹ��ö�Щ
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string d[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, str;
        int len[8] = {3,3,3,3,3,4,3,4}, len_i = digits.length();
        vector<string> vs1, vs2;
        vs1.clear(); 
        vs2.clear();
        if(len_i == 0){
            vs1.push_back("");
            return vs1;
        }
		//�Ȱѵ�һ�����ּ��ϵ���ĸpush�����
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs1.push_back(str);
        }
		/*
		��ÿ��vector�е�Ԫ�أ������׷���¸����ּ��ϵ�ÿ����ĸ��
		��push��vector��Ȼ����ϵ�Ԫ��ȫ�����
		*/
        for(int i=1; i<len_i; i++){
            int size = vs1.size();
            for(int j=0; j<size; j++){
                for(int k=0; k<len[digits[i]-'2']; k++){
                    str = vs1[j]+d[digits[i]-'2'][k];
                    vs2.push_back(str);
                }
            }
            swap(vs1, vs2); //�� vs1 = vs2;
            vs2.clear();
        }
        return vs1;
    }
};