My naive solution:
class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int thousand, hundred, ten, unit;
        string res;
        thousand = num/1000;
        num %= 1000;
        hundred = num/100;
        num %= 100;
        ten = num/10;
        num %= 10;
        unit = num;
        for(int i=0; i<thousand; i++){
            res += "M";
        }
        if(hundred == 9){
            res += "CM";
        }
        else if(hundred >= 5){
            res += "D";
            hundred -= 5;
            for(int i=0; i<hundred; i++){
                res += "C";
            }
        }
        else if(hundred == 4){
            res += "CD";
        }
        else{
            for(int i=0; i<hundred; i++){
                res += "C";
            }
        }
        if(ten == 9){
            res += "XC";
        }
        else if(ten >= 5){
            res += "L";
            ten -= 5;
            for(int i=0; i<ten; i++){
                res += "X";
            }
        }
        else if(ten == 4){
            res += "XL";
        }
        else {
            for(int i=0; i<ten; i++){
                res += "X";
            }
        }
        if(unit == 9){
            res += "IX";
        }
        else if(unit >= 5){
            res += "V";
            unit -= 5;
            for(int i=0; i<unit; i++){
                res += "I";
            }
        }
        else if(unit == 4){
            res += "IV";
        }
        else{
            for(int i=0; i<unit; i++){
                res += "I";
            }
        }
        return res;
    }
};

Much better solution:
class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = {1000, 900, 500, 400, 100, 90,
                             50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
                                 "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / radix[i];
            num %= radix[i];
            for (; count > 0; --count) roman += symbol[i];
        }
        return roman;
    }
};