class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if (!len) return len;
        int min_len = len;
        int start = 0, end = 0, sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            if (sum >= s) {
                end = i;
                min_len = min(min_len, end + 1);
                break;
            }
        }
        if (min_len == len && sum < s) return 0;
        while (true) {
            if (end == len - 1 && sum < s) break;
            if (sum >= s) {
                sum -= nums[start++];
            } else {
                sum += nums[++end];
            }
            if (sum >= s) {
                min_len = min(min_len, end - start + 1);
            }
        }
        return min_len;
    }
};
