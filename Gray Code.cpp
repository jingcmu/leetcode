//位运算法:
//记住即可
class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int range = 1 << n;
        vector<int> v;
        v.resize(range);
        for(int i=0; i<range; i++){
            v[i] = i ^ (i>>1);
        }
        return v;
    }
};