class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len*2);
        
        for (int i = 0; i < len; i++) {
            res[len+i] = res[i] = nums[i];
        }
        
        return res;
    }
};