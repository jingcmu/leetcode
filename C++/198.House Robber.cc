// dp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_money;
        int len = nums.size();
        if (!len) return 0;
        max_money.reserve(len);
        max_money[0] = nums[0];
        max_money[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; ++i) {
            max_money[i] = max(max_money[i-1], nums[i] + max_money[i-2]);
        }
        return max_money[len - 1];
    }
};
