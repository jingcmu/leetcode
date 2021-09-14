class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s(candyType.begin(), candyType.end());
        return min(s.size(), candyType.size()/2);
    }
};