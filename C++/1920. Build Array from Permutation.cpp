class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        
        for (int i = 0; i < len; i++) {
            res[i] = nums[nums[i]];
        }
        
        return res;
    }
};