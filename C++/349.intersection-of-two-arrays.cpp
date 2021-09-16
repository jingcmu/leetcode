class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m;
        vector<int> ret;
        for (int u : nums1) {
            m[u] = true;
        }
        for (int u : nums2) {
            if(m.find(u) != m.end() && m[u]) {
                ret.push_back(u);
                m[u] = false;
            }
        }
        return ret;
    }
};