class Solution {
public:
    int countBinarySubstrings(string s) {
        bool countingOne = s[0] == '1';
        int one = 0, zero = 0, bs = 0;
        
        for (char c : s) {
            if (c == '1') {
                if (countingOne) {
                    one++;
                }
                else if (zero > 0) {
                    bs += min(one, zero);
                    one = 1;
                }
                countingOne = true;
            }
            else {
                if (!countingOne) {
                    zero++;
                }
                else if (one > 0) {
                    bs += min(one, zero);
                    zero = 1;
                }
                countingOne = false;
            }
        }
        
        return bs + min(one, zero);
    }
};