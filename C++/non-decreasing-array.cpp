class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) {
            return true;
        }
        int left = 0, right = 1, one = 0;
        while(right < len) {
            if(nums[left] <= nums[right]) {
                left++;
                right++;
            } else if(one == 0) {
                if (left > 0 &&
                      right < len - 1 && 
                      nums[left-1] > nums[right] &&
                      nums[left] > nums[right+1]) {
                    return false;
                }
                left++;
                right++;
                one = 1;
            } else {
                return false;
            }
        }
        return true;
    }
};