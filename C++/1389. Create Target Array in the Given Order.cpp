class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int cap = nums.size();
        list<int> lst;
        vector<int> res(cap);
        
        for (int i = 0; i < cap; i++) {
            auto it = lst.begin();
            advance(it, index[i]);
            lst.insert(it, nums[i]);
        }
        
        std::copy(lst.cbegin(), lst.cend(), res.begin());
        
        return res;
    }
};