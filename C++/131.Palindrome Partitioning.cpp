//actually, this is a better solution, better than the latter one
//since it is much simple and easy to repeat
class Solution {
public:
    bool isPalin(string &s) {
        string s_r = s;
        reverse(s.begin(), s.end());
        return s_r == s;
    }
    
    void partition(int start) {
        if(start > len-1 ) {
            res.push_back(path);
            return;
        }
        for(int i=1; i<=len-start; i++) { // i is len
            string str = s.substr(start, i);
            if(isPalin(str)) {
                path.push_back(str);
                partition(start+i);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string str) {
        len = str.length();
        s = str;
        partition(0);
        return res;
    }
    
private:
    int len;
    string s;
    vector<vector<string>> res;
    vector<string> path;
};




//ֱ������õķ�����
//��Ϊ�����ĿҪ��������ַ������и��ֻ��֣���������ܹ��õ�������i��jλ���Ƿ�Ϊ���ĵ�һ����
//���ԣ������ȵ���setIsPalin�õ������
//tmp.push_back(s.substr(start, end-start+1))���ŵ�λ�úܺã��������ѭ�����棬
//��push��ȥ��Ҫpop������̫�鷳
class Solution {
    vector<vector<string>> result;
public:
    void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--) //�����N-2ѭ����0
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
    
    void part(int start, int end, vector<string> tmp, string &s, vector<vector<bool>> &isPalin, int N){
        tmp.push_back(s.substr(start, end-start+1)); //push��������ܺã���Ϊ�ǿ��������Բ���Ӱ��ԭֵ
        if(end == N-1){ //����Ѿ����ַ����������ˣ����¼
            result.push_back(tmp); 
            return;
        }
        for(int i = end+1; i < N; i++){
            if(isPalin[end+1][i]){
                part(end+1, i, tmp, s, isPalin);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        int N = s.size();
        vector<vector<bool>> isPalin(N, vector<bool>(N, true));
        setIsPalin(s, isPalin, N);
        vector<string> tmp;
        for(int i = 0; i < N; i++){
            if(isPalin[0][i]){ //�����0��i�ǻ��ģ���������ַ����ж��Ƿ��ܻ���
                part(0, i, tmp, s, isPalin, N);
            }
        }
        return result;
    }
};

���У�
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--)
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
��������д�ɣ�
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = 0; i < N-1; i++)
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
���ǿ���д�ɣ�
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--)
            for(int j = N-1; j >= i+1; j--)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
Ϊʲô��
	��һ�£����Ҫ����f[1][6]����Ҫ֪��f[2][5]��
	f[2][5]�ļ���Ҫ֪��f[3][4]������i�ǴӺ���ǰ��������У�
	j�Ļ�û��ϵ������֮��û��������ϵ


