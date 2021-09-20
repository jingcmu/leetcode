class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0};
        int len = 1;
        int cur = 0;
        
        for (int i = 1; i <= n;) {
            if (cur < len) {
                res.push_back(res[cur++] + 1);
                i++;
            } else {
                cur = 0;
                len <<= 1;
            }
        }
        
        return res;
    }
};