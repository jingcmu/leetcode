class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        string s = "";
        int rem;
        
        if (n == 0) {
            return "0";
        }
        
        while (n != 0) {
            rem = n % 16;
            if (rem > 9) {
                s += (rem - 10 + (int)'a');
            } else {
                s += (rem + (int)'0');
            }
            n /= 16;
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};