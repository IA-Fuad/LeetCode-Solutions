class Solution {
    bool isPrime(int n) {
        int sq = sqrt(n);
        for (int i = 2; i <= sq; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    int rec(int n) {
        if (isPrime(n)) return n;
        
        int steps = n;
        for (int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                int x = rec(i) + n/i;
                steps = min(steps, x);
            }
        }
        
        return steps;
    }
    
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        vector<int> dp(n+1, INT_MAX);
        
        return rec(n);
    }
};