class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<char> v;
        int len = s.length();
        if(len == 0){
            return true;
        }
        for(int i=0; i<s.length(); i++){
            int diff=0; 
            if(v.size()){
                diff = s[i] - v[v.size()-1];
            }
            if(diff>0 && diff < 3){
                v.pop_back();
            }
            else{
                v.push_back(s[i]);
            }
        }
        if(v.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};