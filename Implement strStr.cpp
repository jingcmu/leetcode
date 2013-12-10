class Solution {
public:
    char *strStr(char *haystack, char *needle)  
    {  
        if(!haystack || !needle) return nullptr;
        int m = strlen(haystack);
        int n = strlen(needle);
        for(int i=0; i<=m-n; i++){ //用暴力法的话，注意这里的等于
            int j = 0;
            for(; j<n; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == n) return haystack+i;
        }
        return nullptr;
    }  
};