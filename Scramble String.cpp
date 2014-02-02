/*
思路：
首先想到的是递归（即深搜），对两个string 进行分割，然后比较四对字符串。代码虽然简单，
但是复杂度比较高。有两种加速策略，一种是剪枝，提前返回；一种是加缓存，缓存中间结果，即
memorization（翻译为记忆化搜索）。
剪枝可以五花八门，要充分观察，充分利用信息，找到能让节点提前返回的条件。例如，判断
两个字符串是否互为scamble，至少要求每个字符在两个字符串中出现的次数要相等，如果不相等
则返回false。
加缓存，可以用数组或HashMap。本题维数较高，用HashMap，map 和unordered_map 均可。
既然可以用记忆化搜索，这题也一定可以用动规。设状态为f[n][i][j]，表示长度为n，起
点为s1[i] 和起点为s2[j] 两个字符串是否互为scramble，则状态转移方程为
f[n][i][j] = (f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j])
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if(len != s2.length()) return false;
        bool res[len+1][len][len];
        memset(res, false, sizeof(bool)*(len+1)*len*len);
		//初始化
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                res[1][i][j] = s1[i]==s2[j]; //长度为1，起点为s1[i]和s2[j]的字符串是否互为scramble
            }
        }
        
        for(int l=2; l<=len; l++){ //l stand for length
            for(int i=0; i<=len-l; i++){  //注意等于号，s1的起点
                for(int j=0; j<=len-l; j++){ //s2的起点
                    for(int divlen=1; divlen<l && !res[l][i][j]; divlen++){ //遍历分割点
                        if((res[divlen][i][j] && res[l-divlen][i+divlen][j+divlen]) 
                            || (res[divlen][i][j+l-divlen] && res[l-divlen][i+divlen][j])){
                            res[l][i][j] = true;
                            break;   //有一次true就可以了
                        }
                    }
                }
            }
        }
        return res[len][0][0];
    }
};