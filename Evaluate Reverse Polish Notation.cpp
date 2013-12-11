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