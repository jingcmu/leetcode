class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int len = s.size();
        
        // Used to record the distance from one direction to the character c
        int toC = len + 1;
        for (int i = 0; i < len; i++) {
            if (s[i] == c) {
                toC = 0;
            }
            res.push_back(toC);
            toC++;
        }
        
        toC = len + 1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == c) {
                toC = 0;
            }
            res[i] = min(res[i], toC);
            toC++;
        }
        return res;
    }
};