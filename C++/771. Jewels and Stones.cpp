class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s_jewels;
        
        for (char c : jewels) {
            s_jewels.emplace(std::move(c));
        }
        
        int j_num = 0;
        for_each (stones.begin(), stones.end(), 
                  [&](const char& c)
                  { if (s_jewels.find(c) != s_jewels.end()) j_num++; });
        
        return j_num;
    }
};