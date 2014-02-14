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