//λ���㷨:
//��ס����
class Solution {
public:
    vector<int> grayCode(int n) {
        int range = 1 << n;
        vector<int> v(range);
        for(int i=0; i<range; i++){
            v[i] = i ^ (i>>1);
        }
        return v;
    }
};