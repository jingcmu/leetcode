class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        auto ret = 0;
        for(auto i = 0; i < 32; i++) {
            //把n最右边的，顶到ret最左边
            ret = (ret << 1) + (n & 1);
            n >>= 1;
        }
        return ret;
    }
};