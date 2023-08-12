class Solution {
    unordered_map<int, double> p;
    
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return (1.0 / x);
        if (p.find(n) != p.end()) return p[n];
        
        int a = n / 2;
        int b = (n&1) ? ((n < 0) ? a - 1 : a + 1) : a;
        
        return p[n] = myPow(x, a) * myPow(x, b);
    }
};