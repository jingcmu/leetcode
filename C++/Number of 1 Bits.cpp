class Solution {
public:
    int hammingWeight(uint32_t n) {
        int t[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
        return t[n & 0xf] + t[(n >> 4) & 0xf] + t[(n >> 8) & 0xf] + t[(n >> 12) & 0xf] +
               t[(n >> 16) & 0xf] + t[(n >> 20) & 0xf] + t[(n >> 24) & 0xf] + t[(n >> 28) & 0xf];
    }
};