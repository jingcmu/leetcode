class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v_res;
        int len = nums.size();
        int start = 0;
        
        while(start < len) {
            int end = start;
            while(end < len - 1 && nums[end+1] == nums[end] + 1) {
                end++;
            }
            
            if(end == start) {
                v_res.push_back(to_string(nums[end]));
            } else {
                v_res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            
            start = end + 1;
        }
        return v_res;
    }
};