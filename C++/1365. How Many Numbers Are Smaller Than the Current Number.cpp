class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cap = nums.size();
        vector<int> res(cap);
        
        for (int i = 0; i < cap; i++) {
            int n = 0;
            for (int j = 0; j < cap; j++) {
                if (nums[j] < nums[i]) {
                   n ++;
                }
            }
            res[i] = n;
        }
        
        return res;
    }
};