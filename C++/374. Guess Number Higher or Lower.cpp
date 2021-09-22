/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        long long i = (l + r)/2;
        int g = guess(i);
        while (g != 0) {
            if (g > 0) {
                l = i+1;
            } else {
                r = i-1;
            }
            i = (l + r)/2;
            g = guess(i);
        }
        return i;
    }
};