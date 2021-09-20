class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        multiset<int> m(nums2.begin(), nums2.end());
        
        for (int i = 0; i < nums1.size(); i++) {
            auto it = m.find(nums1[i]);
            if (it != m.end()) {
                res.push_back(nums1[i]);
                m.erase(it);
            }
        }
        
        return res;
    }
};