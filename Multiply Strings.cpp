/*
采用字符串操作：
string multiply(string num1, string num2) 完成两个字符串相乘，调用如下两个函数：
string multiply(string num, char c) 和 string add(string num1, string num2)
分别完成一个字符串和一个char相乘 以及 两个字符串相加，
这些都是基本的。
*/
class Solution {
public:
	//模拟加法操作，一位一位加，最后不要忘了判断进位
    string add(string num1, string num2) {
        int len_a = num1.length(), temp;
        int len_b = num2.length();
        int carry = 0;
        string res = "";
        if(len_a < len_b) { //保证第一个字符串更长
            return add(num2, num1);
        }
        for(int i=0; i<len_b; i++) { 
            temp = (num1[i]-'0')+(num2[i]-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        for(int i=len_b; i<len_a; i++) {
            temp = (num1[i]-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        if(carry){
            res += (carry+ '0');
        }
        return res;
    }
    
	//比上面的加法更简单
    string multiply(string num, char c) {
        int len = num.length(), carry = 0, temp;
        string res = "";
        for(int i=0; i<len; i++){
            temp = (num[i]-'0')*(c-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        if(carry){
            res += (carry+'0');
        }
        return res;
    }
    //通过调用上面两个函数实现
    string multiply(string num1, string num2) {
        int len_a = num1.length(), temp;
        int len_b = num2.length();
        int carry = 0;
        string c = "", num = "0";
        if(len_a<len_b){
            return multiply(num2, num1);
        }
		//把数的顺序反过来，便于操作
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<len_b; i++){
            if(num2[i] != '0'){
                c = multiply(num1, num2[i]);
            
                for(int j=0; j<i; j++){
                    c = c.insert(0, "0");
                }
                num = add(num, c);
            }
        }
        reverse(num.begin(), num.end());
        return num;
    }
};