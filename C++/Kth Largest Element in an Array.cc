
// 最简单解法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

// priority queue 解法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            if (pq.size() < k)
                pq.push(nums[i]);
            else {
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};

