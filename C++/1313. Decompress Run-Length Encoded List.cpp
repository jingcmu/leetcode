class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int cap = nums.size();
        
        for (int i = 0; i < cap; i+=2) {
            for (int j = 0; j < nums[i]; j++) {
                res.push_back(std::move(nums[i+1]));
            }
        }
        
        return res;
    }
};