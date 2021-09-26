class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int cap = nums.size();
        vector<int> res(cap);
        int sum = 0;
        
        for (int i = 0; i < cap; i++) {
            sum += nums[i];
            res[i] = sum;
        }
        
        return res;
    }
};