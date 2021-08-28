class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        auto m = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            //用map记录下上一次碰到num[i]的位置，这是最近的位置了
            m[nums[i]] = i;
        }
        return false;
    }
};