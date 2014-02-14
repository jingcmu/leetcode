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
		//先把第一个数字键上的字母push入队列
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs.push_back(str);
        }
		/*
		对每个vector中的元素，往其后追加下个数字键上的每个字母，
		并push入vector，然后把老的元素全部清空
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

//换种写法，看是不是更好懂些
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
		//先把第一个数字键上的字母push入队列
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs1.push_back(str);
        }
		/*
		对每个vector中的元素，往其后追加下个数字键上的每个字母，
		并push入vector，然后把老的元素全部清空
		*/
        for(int i=1; i<len_i; i++){
            int size = vs1.size();
            for(int j=0; j<size; j++){
                for(int k=0; k<len[digits[i]-'2']; k++){
                    str = vs1[j]+d[digits[i]-'2'][k];
                    vs2.push_back(str);
                }
            }
            swap(vs1, vs2); //或 vs1 = vs2;
            vs2.clear();
        }
        return vs1;
    }
};