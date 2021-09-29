class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int len = encoded.size();
        vector<int> res(len + 1);
        
        res[0] = first;
        for_each()
        for (int i = 1; i <= len; i++) {
            res[i] = encoded[i-1] ^ res[i-1];
        }
        
        return std::move(res);
    }
};