class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int l = 0, r = len-1;
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
        
        while (l < r) {
            if (set.find(s[l]) != set.end() && set.find(s[r]) != set.end()) {
                swap(s[l++], s[r--]);
            } else {
                if (set.find(s[l]) == set.end()) {
                    l++;
                }

                if (set.find(s[r]) == set.end()) {
                    r--;
                }
            }
        }
        return s;
    }
};