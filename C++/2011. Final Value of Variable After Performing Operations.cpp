class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        int cap = operations.size();
        
        for (int i = 0; i < cap; i++) {
            if (operations[i][1] == '+') {
                val++;
            } else {
                val--;
            }
        }
        
        return val;
    }
};