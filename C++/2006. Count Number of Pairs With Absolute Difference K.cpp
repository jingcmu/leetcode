class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int pairs = 0;
        int cap = nums.size();
        
        for (int i = 0; i < cap; i++) {
            for (int j = i + 1; j < cap; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    pairs ++;
                }
            }
        }
        
        return pairs;
    }
};