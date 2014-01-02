1. 暴力匹配法
关于那个等于号，考虑下从m-n到m-1正好长度是n
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

2. KMP
class Solution {
public:
	char *strStr(const char *haystack, const char *needle) {
		int pos = kmp(haystack, needle);
		if (pos == -1) return nullptr;
		else return (char*)haystack + pos;
	}
private:
	/*
	* @brief 计算部分匹配表，即next 数组.
	**
	@param[in] pattern 模式串
	* @param[out] next next 数组
	* @return 无
	*/
	static void compute_prefix(const char *pattern, int next[]) {
		int i;
		int j = -1;
		const int m = strlen(pattern);
		next[0] = j;
		for (i = 1; i < m; i++) {
			while (j > -1 && pattern[j + 1] != pattern[i]) {
				//用前面匹配过的前缀试验
				j = next[j];
			}

			if (pattern[i] == pattern[j + 1]) j++;
			next[i] = j;
		}
	}
	/*
	* @brief KMP 算法.
	**
	@param[in] text 文本
	* @param[in] pattern 模式串
	* @return 成功则返回第一次匹配的位置，失败则返回-1
	*/
	static int kmp(const char *text, const char *pattern) {
		int i;
		int j = -1;
		const int n = strlen(text);
		const int m = strlen(pattern);
		if (n == 0 && m == 0) return 0; /* "","" */
		if (m == 0) return 0; /* "a","" */
		int *next = (int*)malloc(sizeof(int) * m);
		compute_prefix(pattern, next);
		for (i = 0; i < n; i++) {
			while (j > -1 && pattern[j + 1] != text[i]) {
				//如果不匹配 回退到前一个最大前缀
				j = next[j];
			}
			if (text[i] == pattern[j + 1]) j++;
			if (j == m - 1) {
				free(next);
				return i-j;
			}
		}
		free(next);
		return -1;
	}
};