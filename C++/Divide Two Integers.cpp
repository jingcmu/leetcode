//ºÜ¼òµ¥£¬Ïñ·¢TCP°üÄÇÑù£¬Ã¿´ÎÔö´óÒ»±¶
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0, multior = 0;
		//Ò»¶¨ÒªÏÈ×ª³Élong long, ²»È»»á±»INT_MIN·³ËÀ
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        while(a >= b){
            if(a >= (b<<multior)) {
                res += (1<<multior);
                a -= (b<<multior);
                ++multior;
            }
            else {
                multior = 0;
            }
        }
		//ÅÐ¶ÏÁ½¸öÊý·ûºÅÊÇ·ñÏàÍ¬£¬²»ÏàÍ¬Ôò·µ»Ø¸ºÊý
        return ((dividend^divisor)>>31)? 0-res:res;
    }
};

//Second Try:
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend>>31)^(divisor>>31);
        long long dend = abs((long long)dividend);
        long long dsor = abs((long long)divisor);
        long long res = 0;
        while(dend >= dsor) {
            int mul = 0;
            while(dend >= (dsor << mul)) {
                dend -= (dsor << mul);
                res += (1<<mul);
                mul++;
            }
        }
        return sign?(long long)0-res:res;
    }
};  