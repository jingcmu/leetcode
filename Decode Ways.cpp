class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.length();
        vector<int> v;
        v.resize(len+1);
        if(len == 0 || s[0] == '0'){
            return 0;
        }
        v[0] = 1;
        v[1] = 1;
        for(int i=2; i<=len; i++){
            if(s[i-1] == '0'){
                if(s[i-2]-'0' <= 2 && s[i-2]-'0' > 0){
                    v[i] = v[i-2];
                }
                else{
                    return 0;
                }
            }
            else if(s[i-2] == '0'){
                v[i] = v[i-1];
            }
            else if(s[i-2]=='1' || (s[i-2] == '2' && s[i-1]-'0'<7)){
                    v[i] = v[i-1]+v[i-2];
            }
            else if(s[i-2]-'0'>2 || (s[i-2] == '2' && s[i-1]-'0'>6)){
                v[i] = v[i-1];
            }
        }
        return v[len];
    }
};