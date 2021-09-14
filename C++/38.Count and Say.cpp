//模拟
/*
传入字符串，模拟数的动作，计算有几个连续的，记录下来，然后返回字符串
*/
class Solution {
public:
    string countAndSay(string str){
        string s = "";
        int count, len = str.length();
        count = 1;
        for(int i=0; i<=len-1; i++){
            if(i<len-1 && str[i] == str[i+1]){
                count++; //记录有几个连续的字符
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