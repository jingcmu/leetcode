class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_money;
        int len = nums.size();
        if (!len) return 0;
        if (len == 1) return nums[0];
        max_money.reserve(len);
        max_money[0] = nums[0];
        max_money[1] = max(nums[0], nums[1]);
        // 先忽略最后一个屋子
        for (int i = 2; i < len - 1; ++i) {
            max_money[i] = max(max_money[i-1], nums[i] + max_money[i-2]);
        }
        // 得到除最后一个屋子外的最大值
        int max_candidate = max_money[len - 2];
        nums[0] = nums[len - 2] = 0;
        max_money[0] = 0;
        max_money[1] = nums[1];
        // 最后一个屋子一定要抢的话，忽略第一个屋子和倒数第二个屋子
        for (int i = 2; i < len; ++i) {
            max_money[i] = max(max_money[i-1], nums[i] + max_money[i-2]);
        }
        return max(max_candidate, max_money[len - 1]);
    }
};
