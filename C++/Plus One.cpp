My solution:
//很简单，用carry不断的进位，如果不需要进位就返回即可，
//如果一直都要进位，就最后在开头插入个1
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int carry = 1;
        for(int i=len-1; i>=0; i--){
            digits[i] += carry;
            if(digits[i] >= 10){
                digits[i] %= 10;
            }
            else{
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

Second Try:
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for(int i=0; i<digits.size(); i++) {
            digits[i] += (carry);
            if(digits[i] > 9) {
                digits[i] %= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        if(carry) {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};