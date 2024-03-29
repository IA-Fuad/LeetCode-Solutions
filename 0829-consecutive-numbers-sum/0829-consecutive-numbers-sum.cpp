class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int consCount = 0;
        
        for (int k = 1; k*(1+k) <= 2*n; k++) {
            if ((n - (k * (1 + k)) / 2) % k == 0) {
                consCount++;        
            }
        }
        
        return consCount;
    }
};

/*

x+1, x+2, x+3, x+k

kx + k(1 + k)/2 = n
kx = n - k(1+k)/2


n - k(1+k)/2 > 0
n > k(1+k)/2
2n > k(1+k)

*/