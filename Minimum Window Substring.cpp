class Solution {
public:
      bool valid(int num1[], int num2[]){
        for(int i=0; i<256; i++){
            if(num1[i]<num2[i]){
                return false;
            }
        }
		return true;
    }
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int s_num[256], t_num[256], c_num[256];
        int lenS = S.length(), lenT = T.length();
        int head = 0, tail = 0, minLen = lenS, head_min=0;
		memset(s_num,0,sizeof(s_num));
		memset(t_num,0,sizeof(s_num));
		memset(c_num,0,sizeof(s_num));
        if(lenS<lenT) return "";
        for(int i=0; i<lenS; i++){
            s_num[S[i]]++;
        }
        for(int i=0; i<lenT; i++){
            t_num[T[i]]++;
        }
        if(!valid(s_num, t_num)){
            return "";
        }
        c_num[S[0]]++;
        while(tail<lenS){
            //如果不能包住,tail右移
            if(!valid(c_num, t_num) || head>tail){
                c_num[S[++tail]]++;
            }
            //如果全包住,head右移
            else{
                if(tail-head+1 < minLen){
                    minLen = tail-head+1;
                    head_min = head;
                }
                c_num[S[head++]]--;
            }
        }
        return S.substr(head_min, minLen);
    }
};