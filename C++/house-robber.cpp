class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto sz = nums.size();
        if(sz == 1) return nums[0];
        auto prev = nums[0];
        auto cur = max(prev, nums[1]);
        for (auto i = 2; i < sz; i++) {
            auto tmp = cur;
            //prev是[i-2],右边cur是[i-1],左边cur是[i]
            //prev+nums[i]跳过nums[i-1]（不考虑取nums[i-1]）
            //cur考虑取nums[i-1]
            cur = max(cur, prev+nums[i]);
            prev = tmp;
        }
        return cur;
    }
};