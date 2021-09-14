class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (countOne(i) + countOne(j) == turnedOn) {
                    res.push_back(to_string(i) + (j<10?":0":":") + to_string(j));
                }
            }
        }
        return res;
    }
    int countOne(int n) {
        int res = 0;
        while(n > 0) {
            res += (n&0x1);
            n >>= 1;
        }
        return res;
    }
};