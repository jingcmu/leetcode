/*
stoi可以把字符串转成数字，是c++的库函数
这题其实很简单，遇到数字就压栈，遇到操作符就出栈两个数进行运算，把结果压栈
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> num;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i].size() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')){
                num.push(stoi(tokens[i]));
            }
            else{
                int a, b;
                b = num.top(); num.pop();
                a = num.top(); num.pop();
                switch(tokens[i][0]){
                    case '+':
                    num.push(a+b);
                    break;
                    case '-':
                    num.push(a-b);
                    break;
                    case '*':
                    num.push(a*b);
                    break;
                    case '/':
                    num.push(a/b);
                    break;
                }
            }
        }
        return num.top();
    }
};