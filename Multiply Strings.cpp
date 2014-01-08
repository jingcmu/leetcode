class Solution {
public:
    string add(string num1, string num2){
        int len_a = num1.length(), temp;
        int len_b = num2.length();
        int carry = 0;
        string res = "";
        if(len_a<len_b){
            return add(num2, num1);
        }
        for( int i=0; i<len_b; i++){
            temp = (num1[i]-'0')+(num2[i]-'0')+carry;
            carry = temp/10;
            temp%=10;
            res += (temp+'0');
        }
        for( int i=len_b; i<len_a; i++){
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
    
    string multiply(string num, char c){
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
    
    string multiply(string num1, string num2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len_a = num1.length(), temp;
        int len_b = num2.length();
        int carry = 0;
        string c = "", num = "0";
        if(len_a<len_b){
            return multiply(num2, num1);
        }
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