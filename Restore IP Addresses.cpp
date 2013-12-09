class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
private:
    //start: 从s的哪里开始 step: 当前ip段号, ip: 中间ip结果
    void dfs(string s, int start, int step, string ip, vector<string> &res){
        int len = s.length();
        if(len == start && step == 4){
            ip.resize(ip.size()-1); //去掉最后一个'.'
            res.push_back(ip);
            return;
        }
        
        //剪枝
        if((len - start > (4-step)*3) || (len - start < 4 - step)){
            return;
        }
        
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num*10 + (s[i]-'0');
            ip += s[i];
            if(num <= 255){
                dfs(s, i+1, step+1, ip+'.', res);
            }
            if(!num) break;  //允许单个0，不允许前缀0
        }
    }
};