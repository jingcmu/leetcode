class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0, multior = 0;
		//一定要先转成long long, 不然会被INT_MIN烦死
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
        return ((dividend^divisor)>>31)? 0-res:res;
    }
};