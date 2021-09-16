//2015-05-17
class Solution {
public:
    string longestPalindrome(string s) {
        s_ = s;
        len_ = s_.length();
        longest_ = "";
        for (int i = 0; i < len_; ++i) {
            string tmp = palindrome(i, i);
            if (tmp.length() > longest_.length())
                longest_ = tmp;
            if (i + 1 < len_ && s_[i] == s_[i + 1]) {
                tmp = palindrome(i, i + 1);
                if (tmp.length() > longest_.length())
                    longest_ = tmp;
            }
        }
        return longest_;
    }
private:
    string palindrome(int start, int end) {
        while (start >= 0 && end < len_) {
            if (s_[start] != s_[end]) break;
            start--, end++;
        }
        return s_.substr(start + 1, end - start - 1);
    }
    string s_;
    int len_;
    string longest_;
};

//思路就是，以每个字符为中点向两边延伸（只要满足回文）
//能延展的最长的保留下来输出，要考虑奇数回文和偶数回文的情况
class Solution {
public:
    string palindrome(string s, int i, int j, int len){
        string str;
        int start, end;
        start = i;
        end = j;
        while(start >= 0 && end < len){
            if(s[start] != s[end]){
                break;
            }
			start--; end++;
        }
        start++;
        end--;
        return s.substr(start, end-start+1);
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        string longestString = "";
        for(int i=0; i<len; i++){
            string str1 = palindrome(s, i, i, len); //奇数回文
            if(str1.length() > longestString.length()){
                longestString = str1;
            }
            if(i+1 < len && s[i] == s[i+1]){
                string str2 = palindrome(s, i, i+1, len);//偶数回文
                if(str2.length() > longestString.length()){
                    longestString = str2;
                }
            }
        }
        return longestString;
    }
};
