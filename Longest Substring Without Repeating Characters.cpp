class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool flag[32];
        int head=0, tail=head, len = s.length(), max = 1;
        if(!len){
            return 0;
        }
        for(int i=0; i<32; i++){
            flag[i] = false;
        }
        flag[s[head]-'a'] = true;
        while(tail < len-1){
            while(flag[s[tail+1]-'a']){ //existed
                flag[s[head++]-'a'] = false;
            }
            flag[s[++tail]-'a'] = true;
            if(tail-head+1>max){
                max = tail-head+1;
            }
        }
        return max;
    }
};