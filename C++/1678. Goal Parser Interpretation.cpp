class Solution {
public:
    string interpret(string command) {
        string s = "";
        int len = command.size();
        int i = 0;
        
        while (i < len) {
            if (command[i] == 'G') {
                s += 'G';
                i ++;
                continue;
            }
            if (command[i] == '(') {
                if (command[i+1] == 'a') {
                    s += "al";
                    i += 4;
                } else if (command[i+1] == ')') {
                    s += 'o';
                    i += 2;
                }
            }
        }
        
        return s;
    }
};