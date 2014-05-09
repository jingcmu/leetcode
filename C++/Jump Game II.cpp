//Ì°ÐÄ·¨£¬Ã¿´Î×ßÄÜ×ßµÄ×îÔ¶µÄÒ»²½
class Solution {
public:
    int jump(int A[], int n) {
        int longest, step = 1;
        int i = 0;
        if(n <= 1){
            return 0;
        }
        longest = A[0];
        while(longest < n-1 && i < n) {
            int l = longest;
            while(i <= l){ //从上一次最远走到的地方到当前最远能走到的地方
                if(i+A[i] > longest){ //预测并更新下一次最远能走的地方
                    longest = i+A[i];
                }
                i++; 
            }
            step++;
        }
        return step;
    }
};