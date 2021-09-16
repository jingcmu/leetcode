class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = process(n);
        }
        return n == 1;
    }
private:
    int process(int n) {
        int sum = 0;
        while (n > 0) {
            sum += pow(n%10, 2);
            n = n/10;
        }
        return sum;
    }
};