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
    //start: ��s�����￪ʼ step: ��ǰip�κ�, ip: �м�ip���
    void dfs(string s, int start, int step, string ip, vector<string> &res){
        int len = s.length();
        //dfs��ֹ����
		if(len == start && step == 4){
            ip.resize(ip.size()-1); //ȥ�����һ��'.'
            res.push_back(ip);
            return;
        }
        
        //��֦:���ʣ���ִ�����̫��������̫�̣��Ͳ��ü�������
        if((len - start > (4-step)*3) || (len - start < 4 - step)){
            return;
        }
        //dfs���Ĵ���
		//ipһ��ֻ��3λ������ѭ��ֻ��3��
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num*10 + (s[i]-'0');
            ip += s[i]; //��ǰip
            if(num <= 255){ //����С�ڵ���255�������ǺϷ���ip��
                dfs(s, i+1, step+1, ip+'.', res); //�Ϸ�ip�κ����.������һ���ݹ�
            }
            if(!num) break;  //������0��������ǰ׺0
        }
    }
};