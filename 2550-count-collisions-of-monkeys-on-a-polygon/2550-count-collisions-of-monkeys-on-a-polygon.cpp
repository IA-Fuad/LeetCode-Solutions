class Solution {
    const int mod = 1e9 + 7;
    unordered_map<int, int64_t> powers;
    
    int64_t getTwosPowers(int n) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        if (powers.find(n) != powers.end()) return powers[n];
        
        return powers[n] = ((getTwosPowers(n / 2) % mod) * (getTwosPowers((n + 1) / 2) % mod)) % mod;
    }
    
public:
    int monkeyMove(int n) {
        int64_t move = (getTwosPowers(n-1) * 2 - 2) % mod;
        return move;
    }
};

/*

1 2 3

*/