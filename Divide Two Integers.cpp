//很简单，像发TCP包那样，每次增大一倍
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
		//判断两个数符号是否相同，不相同则返回负数
        return ((dividend^divisor)>>31)? 0-res:res;
    }
};