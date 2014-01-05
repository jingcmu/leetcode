//思路其实很简单，就是去找/之间的有效路径，并把有效路径放到vector或者队列中
//显然这里vector就够了
//怎么样找有效路径呢，其实就是找两个/之间的字符串，有几种情况：
//1.中间的字符串为.或者空（出现了连续的/）则直接忽略
//2.中间的字符串为..，则抵消掉上一段路径（要检查有木有上一个路径）
//3.其他字符串一律认为是正常的，加入到vector
//统计完所有路径之后，输出即可，注意如果路径为空则输出根目录/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir;
        
        for(auto it = path.begin(); it != path.end(); ) {
			//这句要是放到循环里面就会runtime error, 
			//因为it如果是end()了(it = jt)，++会出错
			++it; 
            auto jt = find(it, path.end(), '/'); //从it到end找'/'
            dir = string(it, jt); //用iterator构造string
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