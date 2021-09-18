class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> num_map;
        int len = nums.size();
        
        for(int i = 0; i < len; i++) {
            num_map[nums[i]] = true;
        }
        
        for(int i = 0; i < len; i++) {
            if(num_map.find(i) == num_map.end()) {
                return i;
            }
        }
        return len;
    }
};