class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string d[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, str;
        int len[8] = {3,3,3,3,3,4,3,4}, len_i = digits.length();
        vector<string> vs;
        vs.clear();
        if(len_i == 0){
            vs.push_back("");
            return vs;
        }
        for(int i=0; i<len[digits[0]-'2']; i++){
			str = "";
            str += d[digits[0]-'2'][i];
            vs.push_back(str);
        }
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