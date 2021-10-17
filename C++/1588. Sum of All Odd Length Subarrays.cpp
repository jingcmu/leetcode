class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size();
        int sum = 0;
        
        for (int l = 1; l <= len; l += 2) {
            int start = 0;
            while (start + l <= len) {
                for (int j = start; j < start + l; j++) {
                    sum += arr[j];
                }
                start ++;
            }
        }
        
        return sum;
    }
};