My solution:
//�ܼ򵥣���carry���ϵĽ�λ���������Ҫ��λ�ͷ��ؼ��ɣ�
//���һֱ��Ҫ��λ��������ڿ�ͷ�����1
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