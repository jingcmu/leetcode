//这题展示了怎么样即简单又易懂的写出一个好的算法来，
//把独立的功能用函数封装出去，这样问题规模就会缩小
class Solution {
public:
	//判断S是否能包住T，即T中的字符个数要小于S中对应的字符个数
	bool valid(int num1[], int num2[]){
        for(int i=0; i<256; i++){
            if(num1[i]<num2[i]){
                return false;
            }
        }
		return true;
    }
    string minWindow(string S, string T) {
        int s_num[256], t_num[256], c_num[256];
        int lenS = S.length(), lenT = T.length();
        int head = 0, tail = 0, minLen = lenS, head_min=0;
		memset(s_num,0,sizeof(s_num));
		memset(t_num,0,sizeof(s_num));
		memset(c_num,0,sizeof(s_num));
        if(lenS<lenT) return "";
		//统计S中各字符的个数
        for(int i=0; i<lenS; i++){
            s_num[S[i]]++;
        }
		//统计T中各字符的个数
        for(int i=0; i<lenT; i++) {
            t_num[T[i]]++;
        }
        if(!valid(s_num, t_num)){
            return "";
        }
        c_num[S[0]]++;
        while(tail<lenS){
            //如果不能包住,tail右移
            if(!valid(c_num, t_num)) {
                c_num[S[++tail]]++;
            }
            //如果全包住,head右移
            else{
                if(tail-head+1 < minLen) { //刷新最小window长度
                    minLen = tail-head+1;
                    head_min = head;
                }
                c_num[S[head++]]--;
            }
        }
        return S.substr(head_min, minLen); //返回最小window
    }
};