class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        for (int i = 1; i <= n; i++) {
            v[i-1] = to_string(i);
            if (i % 15 == 0) {
                v[i-1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                v[i-1] = "Fizz";
            } else if (i % 5 == 0) {
                v[i-1] = "Buzz";
            }
        }
        return v;
    }
};