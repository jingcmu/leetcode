class Solution {
public:
    string sortSentence(string s) {
        string res = "";
        string word = "";
        vector<pair<int, string>> v;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                v.push_back({s[i]-'0', word});
                word = "";
            } else if (s[i] != ' ') {
                word += s[i];
            }
        }
        
        sort(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++) {
            res += v[i].second;
            if (i != v.size() - 1) {
                res += " ";
            }
        }
        
        return res;
    }
};