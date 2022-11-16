/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        
        while (left <= right) {
            int num = left + (right - left) / 2;
            if (guess(num) == 0) return num;
            if (guess(num) == -1) {
                right = num - 1;
            }
            else {
                left = num + 1;
            }
        }
        
        return -1;
    }
};