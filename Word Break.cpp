class Solution {
private:
    map<int, bool> m;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        if(dict.find(s) != dict.end()){
            return true;
        }
        
        for(int i=1; i<len; i++){
            if(dict.find(s.substr(0,i)) != dict.end()){
                if(!m[i] && wordBreak(s.substr(i,len-i), dict)) {
                    return true;
                }
                else {
                    m[i] = true; //ทรฮสนýมห
                }
            }
        }
        return false;
    }
};