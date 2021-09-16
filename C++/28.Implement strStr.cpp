1. ����ƥ�䷨
�����Ǹ����ںţ������´�m-n��m-1���ó�����n
class Solution {
public:
    char *strStr(char *haystack, char *needle)  
    {  
        if(!haystack || !needle) return nullptr;
        int m = strlen(haystack);
        int n = strlen(needle);
        for(int i=0; i<=m-n; i++){ //�ñ������Ļ���ע������ĵ���
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
	* @brief ���㲿��ƥ�����next ����.
	**
	@param[in] pattern ģʽ��
	* @param[out] next next ����
	* @return ��
	*/
	static void compute_prefix(const char *pattern, int next[]) {
		int i;
		int j = -1;
		const int m = strlen(pattern);
		next[0] = j;
		for (i = 1; i < m; i++) {
			while (j > -1 && pattern[j + 1] != pattern[i]) {
				//��ǰ��ƥ�����ǰ׺����
				j = next[j];
			}

			if (pattern[i] == pattern[j + 1]) j++;
			next[i] = j;
		}
	}
	/*
	* @brief KMP �㷨.
	**
	@param[in] text �ı�
	* @param[in] pattern ģʽ��
	* @return �ɹ��򷵻ص�һ��ƥ���λ�ã�ʧ���򷵻�-1
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
				//�����ƥ�� ���˵�ǰһ�����ǰ׺
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