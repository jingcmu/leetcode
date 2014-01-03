//很简单，就是模拟相加，开始的时候先知道那个串更长，这样好做点
class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length(), temp;
        int len_b = b.length();
        int carry = 0;
        string c = "";
        if(len_a < len_b) {
            return addBinary(b, a);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i = 0; i < len_a; i++){
			if(i < len_b)
				temp = (a[i]-'0')+(b[i]-'0')+carry;
			else
				temp = (a[i]-'0')+carry;
            if(temp >= 2) carry = 1;
            else carry = 0;
            temp %= 2;
            c += (temp+'0');
        }
        if(carry){
            c += (carry+'0');
        }
        reverse(c.begin(), c.end());
        return c;
    }
};