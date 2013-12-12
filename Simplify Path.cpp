class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        
        for(auto it = path.begin(); it != path.end();){
            ++it;
            auto jt = find(it, path.end(), '/'); //¥”itµΩend’“'/'
            dir = string(it, jt);
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