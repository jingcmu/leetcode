class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        int cap = address.size();
        
        for (int i = 0; i < cap; i++) {
            if (address[i] == '.') {
                res += "[.]";
            } else {
                res += address[i];
            }
        }
        
        return res;
    }
};