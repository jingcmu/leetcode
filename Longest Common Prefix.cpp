//从位置0 开始，对每一个位置比较所有字符串（跟第一个字符串比），直到遇到一个不匹配。
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string str=""; //存公共前缀
        bool flag = true;
		if(strs.empty()) return str;
        for(int i=0; i<strs[0].length(); i++){
            for(int j=1; j<strs.size(); j++){
                //每个都跟第一个字符串比较
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