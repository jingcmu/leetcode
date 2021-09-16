class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0; //计数
        int ans = 0; //要找到答案
        for(int i = 0; i < nums.size(); i++) {
            if(ans == nums[i]) {
                cnt++;
            } else if(cnt > 0) {
                cnt--;
            } else {
                ans = nums[i];
                cnt = 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int result = 0;
        int count = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == result) {
                count++;
            } else if (count == 0) {
                result = num[i];
            } else {
                count--;
            }
        }
        return result;
    }
};