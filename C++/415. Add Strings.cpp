class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len = max(len1, len2);
        
        string str = "";
        int carry = 0;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        if (len1 < len2) {
            num1.insert(num1.end(), len2-len1, '0');
        }
        
        if (len2 < len1) {
            num2.insert(num2.end(), len1-len2, '0');
        }
        
        for (int i = 0; i < len; i++) {
            int s = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry = s / 10;
            str += ('0' + (s%10));
        }
        
        if (carry) {
            str += '1';
        }
        
        reverse(str.begin(), str.end());
        
        return str;
    }
};