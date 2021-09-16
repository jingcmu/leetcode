class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto count = 0;
        while(n != 0) {
            //这个操作消除n最后一个1
            n &= (n-1);
            count++;
        }
        return count;
    }
};