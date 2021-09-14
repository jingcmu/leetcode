2015/5/15
class Solution {
public:
    int myAtoi(string str) {
        bool sign = true;
        int sign_num = 0, start;
        long long res = 0;
        for (int i = start; i < str.length(); ++i) {
            if (str[start] == ' ')
                start++;
        }
        for (int i = start; i < str.length(); ++i) {
            if (str[i] == '-') {
                sign = false;
                sign_num++;
                continue;
            } else if (str[i] == '+') {
                sign = true;
                sign_num++;
                continue;
            }
            if (sign_num > 1) return 0;
            if (str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + (str[i] - '0');
                if (res > INT_MAX) {
                    return sign ? INT_MAX : INT_MIN;
                } 
            }
            else {
                return sign ? res : 0 - res;
            }
        }
        return sign ? res : 0 - res;
    }
};

//纯细节题
class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str), i = 0;
        long long value = 0;
        bool b_negative = false;
		//先把前导空格都去掉
        while(str[i] == ' ') i++;
		//再判断第一个字符是不是符号
        if(str[i] == '-' || str[i] == '+'){
            if(str[i] == '-') {
                b_negative = true;
            }
            i++;
        }
		//把前导0都去掉
        while(str[i] == '0') i++;
		//对每个字符循环，遇到非数字就结束
        for(; i<len; i++){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            value = value*10+str[i]-'0';
			//判断是否溢出
            if(value > INT_MAX){
                return b_negative? INT_MIN : INT_MAX;
            }
        }
		//如果是负2147483648则返回-2147483648
        if(b_negative && (value == 2147483648)) return INT_MIN;
		//否则根据符号返回
        return b_negative? 0-value:value;
    }
};
