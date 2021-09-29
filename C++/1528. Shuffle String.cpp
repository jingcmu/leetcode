class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = s.size();
        string res(len, ' ');
        if (len != indices.size()) {
            return res;
        }
        
        for (int i = 0; i < len; i++) {
            res[indices[i]] = s[i]; 
        }
        
        return res;
    }
};