class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto large = std::max_element(candies.begin(), candies.end());
        int cap = candies.size();
        vector<bool> res(cap);
        
        for (int i = 0; i < cap; i++) {
            res[i] = (candies[i] + extraCandies >= *large);
        }
        
        return res;
    }
};