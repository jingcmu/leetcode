//Since leetcode changed the test input, the first version does not work
//假设子串里含有重复字符，则父串一定含有重复字符，单个子问题就可以决定父问题，因此可
//以用贪心法。跟动规不同，动规里，单个子问题只能影响父问题，不足以决定父问题。
//从左往右扫描，当遇到重复字母时，以上一个重复字母的index+1，作为新的搜索起始位置，
//直到最后一个字母，复杂度是O(n)。
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

//Second try:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int longest = 0;
        int len = 0;
        for(int i=0; i<s.size();) {
            if(m.find(s[i]) == m.end() || m[s[i]] == 0) {
                m[s[i]] = 1;
                i++;
                len++;
                longest = max(longest, len);
            }
            else {
                while(m[s[i]] > 0) {
                    m[s[i-len]]--;
                    len--;
                }
            }
        }
        return longest;
    }
};