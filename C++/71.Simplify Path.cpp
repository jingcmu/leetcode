//˼·��ʵ�ܼ򵥣�����ȥ��/֮�����Ч·����������Ч·���ŵ�vector���߶�����
//��Ȼ����vector�͹���
//��ô������Ч·���أ���ʵ����������/֮����ַ������м��������
//1.�м���ַ���Ϊ.���߿գ�������������/����ֱ�Ӻ���
//2.�м���ַ���Ϊ..�����������һ��·����Ҫ�����ľ����һ��·����
//3.�����ַ���һ����Ϊ�������ģ����뵽vector
//ͳ��������·��֮��������ɣ�ע�����·��Ϊ���������Ŀ¼/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        
        for(auto it = path.begin(); it != path.end(); ) {
			//���Ҫ�Ƿŵ�ѭ������ͻ�runtime error, 
			//��Ϊit�����end()��(it = jt)��++�����
			++it; 
            auto jt = find(it, path.end(), '/'); //��it��end��'/'
            dir = string(it, jt); //��iterator����string
            if(!dir.empty() && dir != "."){
                if(dir == ".."){
                    if(!dirs.empty()) {
                        dirs.pop_back();
                    }
                }
                else{
                    dirs.push_back(dir);
                }
            }
            it = jt;
        }
        
        string res = "";
        if(dirs.empty()) return "/";
        else{
            for(int i=0; i<dirs.size(); i++){
                res = res+"/"+dirs[i];
            }
        }
        return res;
    }
};