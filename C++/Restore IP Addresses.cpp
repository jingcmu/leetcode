//My solution is better than D's solution I think
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(!remain_valid(s, 4)) return res;
        dfs(s, "", 1);
        return res;
    }
    
private: 
    vector<string> res;
    void dfs(string s, string ip, int cur_index) {
        string ip_r = ip;
        if(cur_index == 4) {
            if( valid(s) ) {
                ip += s;
                res.push_back(ip);
            }
            return;
        }
        for(int i=1; i<=min(3, (int)s.length()); i++) {
            if( valid(s.substr(0,i)) && remain_valid(s.substr(i), 4 - cur_index) ) {
                ip += (s.substr(0,i) + ".");
                dfs(s.substr(i), ip, cur_index+1);
                ip = ip_r;
            }
        }
    }
    
    bool remain_valid(string s, int n) {
        int len = s.length();
        if(len > n*3 || len < n) return false;
        return true;
    }
    
    bool valid(string s) {
        int num = atoi(s.c_str());
        if(s[0] == '0' && s.length() > 1) return false;
        if(num > 255) return false;
        return true;
    }
};

//D's solution:
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
        //dfs终止条件
		if(len == start && step == 4){
            ip.resize(ip.size()-1); //去掉最后一个'.'
            res.push_back(ip);
            return;
        }
        
        //剪枝:如果剩余字串长度太长，或者太短，就不用继续搜了
        if((len - start > (4-step)*3) || (len - start < 4 - step)){
            return;
        }
        //dfs核心代码
		//ip一级只有3位，所以循环只需3次
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num*10 + (s[i]-'0');
            ip += s[i]; //当前ip
            if(num <= 255){ //满足小于等于255的数才是合法的ip段
                dfs(s, i+1, step+1, ip+'.', res); //合法ip段后面加.进入下一级递归
            }
            if(!num) break;  //允许单个0，不允许前缀0
        }
    }
};